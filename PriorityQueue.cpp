/*
 * PriorityQueue.cpp
 *
 *  Created on: 18 Mar 2018
 *      Author: gilfredoremon
 */

#include "PriorityQueue.h"

using namespace std;
using namespace minimum_spanning_tree;

Queue_Element::Queue_Element(Node n, unsigned c, Node p): node(n), cost(c), parent(p){};

Queue_Element::~Queue_Element(){};

Queue_Element& Queue_Element::operator= (const Queue_Element& obj)
{
	node = obj.node;
	cost = obj.cost;
	parent = obj.parent;
	return *this;
}

PriorityQueue::PriorityQueue(const unsigned capacity): queue_size(0), capacity(capacity)
{
	heap = new Queue_Element[capacity];
}

PriorityQueue::~PriorityQueue()
{
	delete[] heap;
}

void PriorityQueue::chgPrioirity(const Node x, const unsigned priority)
{

	for(unsigned i = 0; i < queue_size; ++i)
	{
		// Set new cost
		if(heap[i].node == x)
		{
			heap[i].cost = priority;
		}
	}

	// Sort the queue
	Queue_Element tmp;
	for(unsigned i = 0; i < queue_size; ++i)
	{
		for(unsigned j = 0; j < queue_size-1; ++j)
		{
			if(heap[j].cost > heap[j+1].cost)
			{
				tmp = heap[j+1];
				heap[j+1] = heap[j];
				heap[j] = tmp;
			}
		}
	}
}

void PriorityQueue::minPrioirty()
{
	if(0 < queue_size)
	{
		for(unsigned i = 0; i < (queue_size-1); ++i)
		{
			heap[i] = heap[i+1];
		}
		queue_size--;
	}
}

bool PriorityQueue::contains(const Node node) const
{
	for(unsigned i = 0; i < queue_size; ++i)
	{
		if(heap[i].node == node)
		{
			return true;
		}
	}

	return false;
}

unsigned PriorityQueue::get_cost(const Node node) const
{
	for(unsigned i = 0; i < queue_size; ++i)
	{
		if(heap[i].node == node)
		{
			return heap->cost;
		}
	}

	return false;
}

Node PriorityQueue::get_parent(const Node node) const
{
	for(unsigned i = 0; i < queue_size; ++i)
	{
		if(heap[i].node == node)
		{
			return heap[i].parent;
		}
	}

	return Node();
}

void PriorityQueue::set_parent(const Node node, const Node parent)
{
	for(unsigned i = 0; i < queue_size; ++i)
	{
		if(heap[i].node == node)
		{
			heap[i].parent = parent;
		}
	}
}

void PriorityQueue::insert(const Queue_Element queue_element)
{
	bool	 inserted = false;

	// Check if queue_size is already at its top
	if(queue_size < capacity)
	{
		// Insert element in queue based on its cost
		for(unsigned i = 0; i < queue_size; ++i)
		{
			if(queue_element.cost < heap[i].cost)
			{
				// Insert in 'i' index
				for(unsigned j = queue_size; j != i; --j)
				{
					heap[j] = heap[j-1];
				}

				heap[i] = queue_element;

				inserted = true;
				break;
			}
		}
	}
	else
	{
		// Double the capacity of heap
		capacity += capacity;
		Queue_Element* tmp = new Queue_Element [capacity];

		for(unsigned i = 0; i < queue_size+1; ++i)
		{
			if(heap[i].cost < queue_element.cost)
			{
				tmp[i] = heap[i];
			}
			else
			{
				if(!inserted)
				{
					tmp[i] = queue_element;
					tmp[i+1] = heap[i];
					inserted = true;
				}
				else
				{
					tmp[i+1] = heap[i];
				}
			}
		}

		delete[] heap;
		heap = tmp;
	}

	if(!inserted)
	{
		// Insert at end of queue if cost is higher...
		heap[queue_size] = queue_element;
	}

	// Increase the queue size
	queue_size++;
}

Queue_Element PriorityQueue::top() const
{
	if(0 < queue_size)
	{
		return heap[0];
	}
	else
	{
		return Queue_Element();
	}
}

Queue_Element PriorityQueue::element_idx(const unsigned i) const
{
	if((0 < queue_size) &&
	   (queue_size > i))
	{
		return heap[i];
	}
	else
	{
		return Queue_Element();
	}
}

size_t PriorityQueue::size() const
{
	return queue_size;
}
