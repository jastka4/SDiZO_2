#pragma once
#include "Graph.h"
#include "Node.h"

class ListGraph :
	public Graph
{
	Node **adjacencyList;
public:
	ListGraph(int, bool);
	~ListGraph();

	void print();
	void addEdge(int, int, int);
	void removeEdge(int, int);
	bool isEdge(int, int);
	void primsAlgorithm() {}
	void dijkstrasAlgorithm(int, int);
};
