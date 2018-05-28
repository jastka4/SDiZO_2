#pragma once
#include "IndexOutOfBoundsException.h"
#include <iostream>
#include <iomanip>

class MinHeap
{
	int *heap;
	size_t capacity;
	size_t size;

	size_t getParent(size_t);
	size_t getLeftChild(size_t);
	size_t getRightChild(size_t);
	void relocate(size_t);
	void swap(int*, int*);
	void heapify(size_t);
	void decreaseKey(size_t, int);
	void display(int, int);

public:
	MinHeap();
	~MinHeap();

	size_t getSize();
	int pop();
	void push(int);
	void remove(int);
	size_t find(int);
	void display();
	void displayTree();
};
