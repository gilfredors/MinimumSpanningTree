/*
 * ShortestPath.h
 *
 *  Created on: 19 Mar 2018
 *      Author: gilfredoremon
 */

#ifndef SHORTESTPATH_H_
#define SHORTESTPATH_H_

#include <iostream>
#include "Graph.h"
#include "PriorityQueue.h"

namespace minimum_spanning_tree
{
	class ShortestPath
	{
	public:
		ShortestPath(const Graph& obj);

		~ShortestPath();

		// Find shortest path between u-w and returns
		// sequence of vertices representing shortest path: u-v1-v2-…-vn-w.
		vector<Node> path(const Node u, const Node w);

		// Return the path cost associated with the shortest path.
		unsigned path_size(const Node u, const Node w);

	private:

		vector<Node> compute_dijkstra(const Node u, const Node w, unsigned& path_size);
		void clear_data();

		PriorityQueue closed_set; // Closed set
		PriorityQueue open_set; // Open set
		vector<Node> parent;
		Graph g; // Graph
	};
}

#endif /* SHORTESTPATH_H_ */
