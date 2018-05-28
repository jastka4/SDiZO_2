#include "Graph.h"

Graph::Graph()
{
	edgesCount = 0;
	vertexCount = 0;
	isDirected = false;
}

Graph::Graph(int vertexCount, bool isDirected)
{
	edgesCount = 0;
	this->vertexCount = vertexCount;
	this->isDirected = isDirected;
}

Graph::~Graph(){}
