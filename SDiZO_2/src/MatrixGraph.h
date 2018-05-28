#pragma once
#include "Graph.h"
#include "MinHeap.h"
#include <algorithm>  

class MatrixGraph :
	public Graph
{
	int **incidenceMatrix;

	int minKey(int key[], bool mstSet[]);

public:
	MatrixGraph(int, bool);
	~MatrixGraph();

	void print();
	void addEdge(int, int, int);
	void removeEdge(int, int);
	bool isEdge(int, int);
	void primsAlgorithm();
	int minDistance(int*, bool*);
	void dijkstrasAlgorithm(int, int);
	int isMarked(int, int*, int);
};
