#include "Node.h"
#include <iostream>

Node::Node()
{
	vertex = 0;
	weight = 0;
	next = nullptr;
}

Node::~Node()
{
	next = nullptr;
	vertex = 0;
	weight = 0;
}
