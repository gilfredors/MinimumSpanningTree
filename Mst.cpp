/*
 * Dijkstra.cpp
 *
 *  Created on: 17 Mar 2018
 *      Author: gilfredoremon
 */

#include "Graph.h"
#include "ShortestPath.h"

using namespace minimum_spanning_tree;

int main()
{

	Graph e("ExampleGraphMst");
	Graph a("ExampleA");
	Graph b(20, 0.1);
	vector<Node> mst = e.min_span_tree(0);

	cout << e << endl;

	// Print MST of e, starting at 0
	for(unsigned i = 0; i <mst.size(); ++i)
	{
		cout << "<" << mst[i] << ">";
	}
	cout << endl;

	cout << a << endl;

	mst = a.min_span_tree(0);
	//Print MST of a, starting at 0
	for(unsigned i = 0; i <mst.size(); ++i)
	{
		cout << "<" << mst[i] << ">";
	}
	cout << endl;

	mst = b.min_span_tree(0);
	//Print MST of a, starting at 0
	for(unsigned i = 0; i <mst.size(); ++i)
	{
		cout << "<" << mst[i] << ">";
	}
	cout << endl;

	return 0;
}

