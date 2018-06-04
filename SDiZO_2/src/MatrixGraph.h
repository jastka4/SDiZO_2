#pragma once
#include "Graph.h"
#include "MinHeap.h"
#include <algorithm>  

class MatrixGraph :
	public Graph
{
	int **incidenceMatrix;

	int minKey(int*, bool*);

public:
	MatrixGraph(int, bool);
	~MatrixGraph();

	void print();
	void addEdge(int, int, int);
	void removeEdge(int, int);
	void primsAlgorithm();
	void dijkstrasAlgorithm(int, int);
};
