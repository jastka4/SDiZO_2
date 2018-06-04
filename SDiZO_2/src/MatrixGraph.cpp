#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int vertexCount, bool isDirected) : Graph(vertexCount, isDirected)
{
	incidenceMatrix = new int*[vertexCount];

	for (size_t i = 0; i < vertexCount; i++)
	{
		incidenceMatrix[i] = new int[vertexCount];

		for (size_t j = 0; j < vertexCount; j++)
			incidenceMatrix[i][j] = 0;
	}
}

MatrixGraph::~MatrixGraph()
{
	for (size_t i = 0; i < vertexCount; i++)
		delete[] incidenceMatrix[i];

	delete[] incidenceMatrix;
}

void MatrixGraph::print()
{
	std::cout << "Incidence matrix representation: " << std::endl;

	size_t i, j;

	for (i = 0; i < vertexCount; i++)
	{
		for (j = 0; j < vertexCount; j++)
			std::cout << std::setw(4) << incidenceMatrix[i][j] << "  ";
		
		std::cout << std::endl;
	}
}

void MatrixGraph::addEdge(int origin, int destination, int weight)
{
	if (origin >= 0 && origin < vertexCount && destination >= 0 && destination < vertexCount)
	{
		incidenceMatrix[origin][destination] = 1 * weight;
		if (isDirected)
			incidenceMatrix[destination][origin] = -1 * weight;
		else
			incidenceMatrix[destination][origin] = 1 * weight;

		edgesCount++;
	}
	// else throws error
}

void MatrixGraph::removeEdge(int i, int j)
{
	if (i >= 0 && i < vertexCount && j > 0 && j < vertexCount)
	{
		incidenceMatrix[i][j] = 0;
		incidenceMatrix[j][i] = 0;
	
		edgesCount--;
	}
	// else throws error
}

int MatrixGraph::minKey(int *key, bool *visited)
{
	int min = INT_MAX, min_index;

	for (size_t i = 0; i < vertexCount; i++)
		if (visited[i] == false && key[i] < min)
			min = key[i], min_index = i;

	return min_index;
}

void MatrixGraph::primsAlgorithm()
{
	int *MST = new int[vertexCount];
	int *key = new int[vertexCount];
	bool *visited = new bool[vertexCount];
	int totalCost = 0;

	for (size_t i = 0; i < vertexCount; i++)
	{
		key[i] = INT_MAX;
		visited[i] = false;
	}

	key[0] = 0;
	MST[0] = -1;

	for (size_t count = 0; count < vertexCount - 1; count++)
	{
		int j = minKey(key, visited);

		visited[j] = true;

		for (size_t i = 0; i < vertexCount; i++)
		{
			if (incidenceMatrix[j][i] && visited[i] == false && incidenceMatrix[j][i] < key[i])
			{
				MST[i] = j;
				key[i] = incidenceMatrix[j][i];
			}
		}
	}

	std::cout << "\n\nMinimal Spanning Tree for incidence matrix representation (Prims's algorithm)"
			  << "\n------------------------------------------------------------------------------" << std::endl;
	for (size_t i = 1; i < vertexCount; i++)
	{
		std::cout << "Edge " << MST[i] << " -> " << i << " weight: " << incidenceMatrix[i][MST[i]] << std::endl;
		totalCost += incidenceMatrix[i][MST[i]];
	}
	std::cout << "\nTotal cost: " << totalCost << std::endl;

	delete[] MST;
	delete[] key;
	delete[] visited;
}

void MatrixGraph::dijkstrasAlgorithm(int source, int destination)
{
	if (destination >= vertexCount)
		return; //throws error

	int *distance = new int[vertexCount];
	int *markedVertices = new int[vertexCount];

	for (size_t i = 0; i < vertexCount; i++)
	{
		distance[i] = INT_MAX;
		markedVertices[i] = -1;
	}

	distance[source] = 0;

	MinHeap *vertices = new MinHeap();
	for (size_t i = 0; i < vertexCount; i++)
	{
		vertices->push(i);
	}

	while (vertices->getSize() != 0)
	{
		int i = vertices->pop();
		for (size_t j = 0; j < vertexCount; j++)
		{
			if (incidenceMatrix[i][j] > 0 && distance[j] > distance[i] + incidenceMatrix[i][j])
			{
				distance[j] = distance[i] + incidenceMatrix[i][j];
				markedVertices[j] = i;
			}
		}
	}

	int currentVertex = destination;
	if (distance[currentVertex] == INT_MAX)
		return; //throws error

	std::cout << "\n\nShortest path for incidence matrix representation"
			  << "\n--------------------------------------------------" << std::endl;

	while(currentVertex != -1)
	{
		std::cout << currentVertex;
		currentVertex = markedVertices[currentVertex];
		if (currentVertex != -1)
			std::cout << "<-";
		else
			std::cout << "\n";
	}

	std::cout << "\nTotal cost: " << distance[destination] << std::endl;

	delete[] markedVertices;
	delete[] distance;
}
