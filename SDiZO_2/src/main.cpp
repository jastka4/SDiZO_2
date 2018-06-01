// main.cpp : Defines the entry point for the console application.
#include "Graph.h"
#include "MatrixGraph.h"
#include "ListGraph.h"

int main()
{
	Graph *graph = new MatrixGraph(6, false);
	graph->addEdge(0, 1, 3);
	graph->addEdge(0, 4, 3);
	graph->addEdge(1, 2, 1);
	graph->addEdge(2, 3, 3);
	graph->addEdge(2, 5, 1);
	graph->addEdge(3, 1, 3);
	graph->addEdge(4, 5, 2);
	graph->addEdge(5, 0, 6);
	graph->addEdge(5, 3, 1);
	
	graph->print();
	graph->primsAlgorithm();
	graph->dijkstrasAlgorithm(0, 5);

	Graph *graphL = new ListGraph(6, false);
	graphL->addEdge(0, 1, 3);
	graphL->addEdge(0, 4, 3);
	graphL->addEdge(1, 2, 1);
	graphL->addEdge(2, 3, 3);
	graphL->addEdge(2, 5, 1);
	graphL->addEdge(3, 1, 3);
	graphL->addEdge(4, 5, 2);
	graphL->addEdge(5, 0, 6);
	graphL->addEdge(5, 3, 1);

	graphL->print();
	graphL->primsAlgorithm();
	graphL->dijkstrasAlgorithm(0, 5);
	std::cin.get();

	return 0;
}
