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

	Graph sample("SampleGraph");
	Graph e("ExampleGraphMst");
	Graph a("ExampleA");
	vector<Node> mst = sample.min_span_tree(0);

	// Print MST of e, starting at 0
	cout << endl;
	cout << "MST of Sample Graph provided in instructions of assignment: " << endl;
	for(unsigned i = 0; i <mst.size(); ++i)
	{
		cout << "<" << mst[i] << ">";
	}
	cout << ". Cost: " << sample.cost_min_span_tree(0) << endl << endl;

	cout << "Graph Example 2 Prim: " << endl;
	cout << e << endl;

	// Print MST of e, starting at 0
	mst = e.min_span_tree(0);
	cout << "MST of Example 2 Prim: ";
	for(unsigned i = 0; i <mst.size(); ++i)
	{
		cout << "<" << mst[i] << ">";
	}
	cout << ". Cost: " << e.cost_min_span_tree(0) << endl << endl;

	cout << "Graph of Example 1 Prim: " << endl;
	cout << a << endl;

	mst = a.min_span_tree(0);
	cout << "MST of Example 1 Prim: ";
	//Print MST of a, starting at 0
	for(unsigned i = 0; i <mst.size(); ++i)
	{
		cout << "<" << mst[i] << ">";
	}
	cout << ". Cost: " << a.cost_min_span_tree(0) << endl << endl;

	return 0;
}

