/*
 * Graph.h
 *
 *  Created on: 17 Mar 2018
 *      Author: gilfredoremon
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <vector>
#include <random>

using namespace std;

namespace mst
{
	typedef unsigned Node;
	typedef unsigned Edge;
	typedef unsigned Value;

	const Edge min_range = 1;
	const Edge max_range = 10;
	const Edge no_edge = 0;

	class Graph
	{
	public:

		// Constructor
		Graph(const unsigned nV = 0, const double density = 0, const Edge min_edge = 1, const Edge max_edge = 10);

		// Constructor reading text file
		Graph(const string filename);

		// Copy constructor
		Graph(const Graph& obj);

		// Assignment operator
		Graph& operator= (const Graph& obj);

		// Destructor
		~Graph();

		// Returns the number of vertices in the graph
		unsigned V() const;

		// Returns the number of edges in the graph
		unsigned E() const;

		// Tests whether there is an edge from node x to node y.
		bool adjacent(const Node x, const Node y) const;

		// Lists all nodes y such that there is an edge from x to y.
		vector<Node> neighbors(const Node x) const;

		Edge get_edge(const Node x, const Node y) const;

		friend ostream& operator<<(ostream& os, const Graph& obj);

	private:
		vector<Edge*> data; // Data representation of graph
		unsigned n_v; // Number of vertices
		unsigned n_e; // Number of edges
		mt19937 random_gen; //Standard mersenne_twister_engine seeded with rd()
		uniform_real_distribution<> edge_existence;
		uniform_int_distribution<Edge> edge_prob;
	};

}

#endif /* GRAPH_H_ */
