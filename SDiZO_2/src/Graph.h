#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>

class Graph
{
protected:
	int vertexCount;
	int edgesCount;
	bool isDirected;

public:
	Graph();
	Graph(int, bool);
	virtual ~Graph();

	virtual void print() = 0;
	virtual void addEdge(int, int, int) = 0;
	virtual void removeEdge(int, int) = 0;
	virtual void primsAlgorithm() = 0;
	virtual void kruskalsAlgorithm() = 0;
	virtual void dijkstrasAlgorithm(int, int) = 0;
};
