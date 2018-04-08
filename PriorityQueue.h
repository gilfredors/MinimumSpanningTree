/*
 * PriorityQueue.h
 *
 *  Created on: 18 Mar 2018
 *      Author: gilfredoremon
 */

#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_

#include <iostream>
#include "Graph.h"

using namespace std;

namespace minimum_spanning_tree
{
	struct Queue_Element
	{
		Queue_Element(Node n = 0, unsigned c = 0, Node p = 0);
		~Queue_Element();
		Queue_Element& operator= (const Queue_Element& obj);
		Node			node;
		unsigned		cost;
		Node			parent;
	};

	class PriorityQueue
	{
	public:

		// Constructor
		PriorityQueue(const unsigned capacity = 50);

		// Destructor
		~PriorityQueue();

		// Changes the priority (node value) of queue element.
		void chgPrioirity(const Node x, const unsigned priority);

		// Removes the top element of the queue.
		void minPrioirty();

		// Does the queue contain queue_element.
		bool contains(const Node node) const;

		// Get cost of given node (expected to be in queue)
		unsigned get_cost(const Node node) const;

		// Set parent of given node
		Node get_parent(const Node node) const;

		// Set parent of given node (expected to be in queue)
		void set_parent(const Node node, const Node parent);

		// Insert queue_element into queue
		void insert(const Queue_Element queue_element);

		// Returns the top element of the queue.
		Queue_Element top() const;

		// Return element of given index.
		// If index is out of range top is returned.
		Queue_Element element_idx(const unsigned i) const;

		// Return the number of queue_elements.
		size_t size() const;

	private:
		Queue_Element* heap;
		size_t queue_size;
		unsigned capacity;
	};
}

#endif /* PRIORITYQUEUE_H_ */
