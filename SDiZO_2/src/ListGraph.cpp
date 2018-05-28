#include "ListGraph.h"
#include "MinHeap.h"

ListGraph::ListGraph(int vertexCount, bool isDirected) : Graph(vertexCount, isDirected)
{
	adjacencyList = new Node*[vertexCount];
	
	for (int i = 0; i < vertexCount; i++)
		adjacencyList[i] = nullptr;
}

ListGraph::~ListGraph()
{
	for (int i = 0; i < vertexCount; i++)
		delete adjacencyList[i];
	
	delete[] adjacencyList;
}

void ListGraph::print()
{
	Node* node;

	std::cout << "\nList representation:" << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < vertexCount; i++)
	{
		std::cout << "[" << i << "] =";
		node = adjacencyList[i];

		while (node)
		{
			std::cout << std::setw(3) << node->vertex;
			node = node->next;
		}
		std::cout << std::endl;
	}
}

void ListGraph::addEdge(int origin, int destination, int weight)
{
	Node* newNode = new Node();
	newNode->vertex = destination;
	newNode->weight = weight;
	newNode->next = adjacencyList[origin];
	adjacencyList[origin] = newNode;

	if (!isDirected)
	{
		newNode = new Node();
		newNode->vertex = origin;
		newNode->weight = weight;
		newNode->next = adjacencyList[destination];
		adjacencyList[destination] = newNode;
	}

	edgesCount++;
}

void ListGraph::removeEdge(int i, int j) //edit - fix
{
	if (i >= 0 && i < vertexCount && j > 0 && j < vertexCount)
	{
		adjacencyList[i][j].weight = 0;
		adjacencyList[i][j].vertex = 0;
		adjacencyList[i][j].next = nullptr;

		adjacencyList[j][i].weight = 0;
		adjacencyList[j][i].vertex = 0;
		adjacencyList[j][i].next = nullptr;

		edgesCount--;
	}
	// else throws error
}

bool ListGraph::isEdge(int i, int j)
{
	if (i >= 0 && i < vertexCount && j > 0 && j < vertexCount)
	{
		if (adjacencyList[i][j].weight != 0)
			return true;
		else
			return false;
	}
	else
		return false;
}

void ListGraph::dijkstrasAlgorithm(int source, int destination)
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

	Node* node;
	while (vertices->getSize() != 0)
	{
		int i = vertices->pop();
		node = adjacencyList[i];

		while (node)
		{
			if (node->weight > 0 && distance[node->vertex] > distance[i] + node->weight)
			{
				distance[node->vertex] = distance[i] + node->weight;
				markedVertices[node->vertex] = i;
				std::cout << "Marked: [" << node->vertex << "] = " << i << std::endl;
			}

			node = node->next;
		}
	}

	int currentVertex = destination;
	if (distance[currentVertex] == INT_MAX)
		return; //throws error

	std::cout << "\n\nShortest path for adjacency list representation"
		<< "\n--------------------------------------------------" << std::endl;

	while (currentVertex != -1)
	{
		std::cout << currentVertex;
		currentVertex = markedVertices[currentVertex];
		if (currentVertex != -1)
			std::cout << "<-";
		else
			std::cout << "\n";
	}
	
	std::cout << "\nTotal cost: " << distance[destination] << std::endl;
}