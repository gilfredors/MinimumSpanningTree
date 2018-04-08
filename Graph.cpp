/*
 * Graph.cpp
 *
 *  Created on: 17 Mar 2018
 *      Author: gilfredoremon
 */

#include <random>
#include <fstream>
#include <iterator>
#include "Graph.h"

using namespace std;
using namespace mst;

Graph::Graph(const unsigned nV, const double density, const Edge min_edge, const Edge max_edge):
		data(nV),
		n_v(nV),
		n_e(),
		random_gen(time(0)),
		edge_existence(0.0, 1.0),
		edge_prob(min_edge, max_edge)
{
	// Allocate the memory
	for(unsigned i = 0; i < n_v; ++i)
	{
		data[i] = new Edge[n_v];
	}

	// Generate the graph
	for(unsigned i = 0; i < n_v; ++i)
	{
		for(unsigned j = 0; j < n_v; ++j)
		{
			if(i == j)
			{
				data[i][j] = static_cast<Edge>(0);
			}
			else
			{
				if(edge_existence(random_gen) < density)
				{
					if(static_cast<Edge>(0) == data[i][j])
					{
						n_e++; // Increase number of edges
					}

					// Define the edge cost based on class defined range
					data[i][j] = data[j][i] = edge_prob(random_gen);
				}
				else
				{
					data[i][j] = data[j][i] = static_cast<Edge>(0);
				}
			}
		}
	}
}

// Constructor reading text file
Graph::Graph(const string filename):
		data(),
		n_v(),
		n_e()
{
	ifstream graph_file(filename);

	if(graph_file.is_open())
	{
		istream_iterator<int> start(graph_file), end;
		vector<unsigned> data_file(start, end);
		vector<unsigned>::iterator it = data_file.begin();

		// Get number of vertices
		n_v = *it;

		// Allocate the memory
		for(unsigned i = 0; i < n_v; ++i)
		{
			data[i] = new Edge[n_v];
			memset(data[i], 0, sizeof(Edge) * n_v);
		}

		for(++it ; it != data_file.end(); ++it)
		{
			// Define edge
			data[*it][*(++it)] = *(++it);
		}

		graph_file.close();
	}
	else
	{
		// Could not open file: Empty Graph is created
		n_v = 0;
		n_e = 0;
	}


}

Graph::Graph(const Graph& obj):
		data(obj.V()),
		n_v(obj.V()),
		n_e(obj.E())
{
	// Allocate the memory & copy data
	for(unsigned i = 0; i < n_v; ++i)
	{
		data[i] = new Edge[n_v];

		for(unsigned j = 0; j < n_v; ++j)
		{
			data[i][j] = obj.get_edge(i,j);
		}
	}
}

Graph& Graph::operator= (const Graph& obj)
{
	// Program could check whether obj and referenced object are equal
	// Clear memory if it is not empty
	for(unsigned i = 0; i < n_v; ++i)
	{
		delete[] data[i];
	}

	data.clear(); // Clear vector

	// Copy the data
	n_v = obj.V();
	n_e = obj.E();
	data.resize(n_v);

	// Allocate the memory & copy data
	for(unsigned i = 0; i < n_v; ++i)
	{
		data[i] = new Edge[n_v];

		for(unsigned j = 0; j < n_v; ++j)
		{
			data[i][j] = obj.get_edge(i,j);
		}
	}

	return *this;
}

Graph::~Graph()
{
	for(unsigned i = 0; i < n_v; ++i)
	{
		delete[] data[i];
	}
}


unsigned Graph::V() const
{
	return n_v;
}

unsigned Graph::E() const
{
	return n_e;
}

bool Graph::adjacent(const Node x, const Node y) const
{
	if((x < n_v) && (y < n_v))
	{
		return (data[x][y] != no_edge);
	}
	else
	{
		return false;
	}
}

vector<Node> Graph::neighbors(const Node x) const
{
	vector<Node> neighbors;

	if(x < n_v)
	{
		for(Node i = 0; i < n_v; ++i)
		{
			if(data[x][i])
			{
				neighbors.push_back(i);
			}
		}
	}

	return neighbors;
}

Edge Graph::get_edge(const Node x, const Node y) const
{

	if((x < n_v) && (y < n_v))
	{
		return data[x][y];
	}
	else
	{
		return 0.0;
	}
}

ostream& mst::operator<<(ostream& os, const Graph& obj)
{
	os << "\t";

	for(unsigned i = 0; i < obj.V(); ++i)
	{
		os << i << "\t";
	}

	os << endl;

	for(unsigned i = 0; i < obj.V(); ++i)
	{
		os << i << ":\t";
		for(unsigned j = 0; j < obj.V(); ++j)
		{
			os << obj.get_edge(i, j) << "\t";
		}
		os << endl;
	}

	return os;
}
