/*
 * ShortestPath.cpp
 *
 *  Created on: 19 Mar 2018
 *      Author: gilfredoremon
 */

#include <limits>
#include "ShortestPath.h"

using namespace std;
using namespace minimum_spanning_tree;

ShortestPath::ShortestPath(const Graph& obj): closed_set(PriorityQueue()), parent(vector<Node>(obj.V())), g(obj){};

ShortestPath::~ShortestPath(){};

vector<Node> ShortestPath::compute_dijkstra(const Node u, const Node w, unsigned& path_size)
{
	vector<Node> sequence(0); // Set of Nodes for sequence of shortest path
	vector<Node>::iterator it; // Iterator for sequence vector
	bool w_found = false; // Indicate when destination node is reached
	Queue_Element lcn; // Least cost node of open set

	// Initialize the set of shortest path, origin: Node u¬
	closed_set.insert(Queue_Element(u, 0));

	// Initialize parent list to numeric_limits<unsigned>::max();
	for(unsigned i = 0; i < parent.size(); ++i)
	{
		parent[i] = static_cast<Node>(numeric_limits<unsigned>::max());
	}
	// Excluding source
	parent[u] = 0;

	// Get Neighbors of current node
	vector<Node> ngh = g.neighbors(u);

	if(ngh.size() != 0)
	{
		// Include neighbors in open set
		for(unsigned i = 0; i < ngh.size(); ++i)
		{
			open_set.insert(Queue_Element(ngh[i], g.get_edge(u, ngh[i]), u));
		}

		while(!w_found)
		{
			// Get neighbor of least cost in closed set
			lcn = open_set.top();
			if(closed_set.size() == g.V()+1)
			{
				// No path found...
				clear_data();
				return sequence;
			}
			closed_set.insert(lcn);

			if(w == lcn.node)
			{
				// Stop the algorithm! Destination found
				w_found = true;
			}
			else
			{
				// Removes least cost neighbor from open set
				open_set.minPrioirty();

				// Compute all successors of least cost node
				ngh = g.neighbors(lcn.node);

				if(0 == open_set.size())
				{
					// No more successors! No way found to w
					clear_data();
					return sequence;
				}

				for(unsigned i = 0; i < ngh.size(); ++i)
				{
					if(closed_set.contains(ngh[i]))
					{
						// nothing to do...
					}
					else if((open_set.contains(ngh[i])) &&
							(open_set.get_cost(ngh[i]) > lcn.cost + g.get_edge(lcn.node, ngh[i])))
					{
						// Update cost of element in open set, since it can be lower
						open_set.chgPrioirity(ngh[i], lcn.cost + g.get_edge(lcn.node, ngh[i]));
						open_set.set_parent(ngh[i], lcn.node);
					}
					else if(!open_set.contains(ngh[i]) && !closed_set.contains(ngh[i]))
					{
						// If neighbor is not already in closed or open set, include it in open!
						open_set.insert(Queue_Element(ngh[i], lcn.cost + g.get_edge(lcn.node, ngh[i]), lcn.node));
					}
					else{}
				}
			}
		}
	}
	else
	{
		// Node u have no more neighbors. Short path is empty.
		clear_data();
		return sequence;
	}

	if(true == w_found)
	{
		// Iterate from parent to parent until u...
		sequence.push_back(w);

		Node parent = closed_set.get_parent(w);
		it = sequence.begin();

		// Increment path size by cost w -> parent
		path_size += g.get_edge(w, parent);

		if(parent != u)
		{
			while(parent != u)
			{
				it = sequence.insert(it, parent);
				path_size += g.get_edge(parent, closed_set.get_parent(parent));
				parent = closed_set.get_parent(parent);
			}
		}

		it = sequence.insert(it, u);
	}

	clear_data();
	return sequence;

}

void ShortestPath::clear_data()
{
	unsigned lim = closed_set.size();
	for(unsigned i = 0; i < lim; ++i)
	{
		closed_set.minPrioirty();
	}

	lim = open_set.size();
	for(unsigned i = 0; i < lim; ++i)
	{
		open_set.minPrioirty();
	}
}

vector<Node> ShortestPath::path(const Node u, const Node w)
{
	unsigned path_size = 0;

	return compute_dijkstra(u, w, path_size);
}

unsigned ShortestPath::path_size(const Node u, const Node w)
{
	unsigned path_size = 0;

	if (!compute_dijkstra(u, w, path_size).empty())
	{
		return path_size;
	}
	else
	{
		return 0;
	}

}
