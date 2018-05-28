#include "MinHeap.h"

MinHeap::MinHeap()
{
	size = 0;
	heap = new int[size];
}

MinHeap::~MinHeap()
{
	delete[] heap;
	size = 0;
}

size_t MinHeap::getParent(size_t index)
{
	return (index - 1) / 2;
}

size_t MinHeap::getLeftChild(size_t index)
{
	return (2 * index + 1);
}

size_t MinHeap::getRightChild(size_t index)
{
	return (2 * index + 2);
}

void MinHeap::relocate(size_t newSize)
{
	int* temp = new int[newSize];
	if (newSize >= size)
	{
		for (size_t i = 0; i < size; i++)
		{
			temp[i] = heap[i];
		}
	}
	else
	{
		for (size_t i = 0; i < newSize; i++)
		{
			temp[i] = heap[i];
		}
	}
	delete heap;
	heap = temp;
}

void MinHeap::swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void MinHeap::push(int key)
{
	relocate(size + 1);
	size++;
	int i = size - 1;
	heap[i] = key;

	while (i != 0 && heap[getParent(i)] > heap[i])
	{
		swap(&heap[i], &heap[getParent(i)]);
		i = getParent(i);
	}
}

void MinHeap::decreaseKey(size_t index, int newValue)
{
	heap[index] = newValue;
	while (index != 0 && heap[getParent(index)] > heap[index])
	{
		swap(&heap[index], &heap[getParent(index)]);
		index = getParent(index);
	}
}

int MinHeap::pop()
{
	if (size <= 0)
	{
		throw IndexOutOfBoundsException("Heap is empty");
	}
	else if (size == 1)
	{
		size--;
		return heap[0];
	}

	int root = heap[0];
	heap[0] = heap[size - 1];
	relocate(size - 1);
	size--;
	heapify(0);

	return root;
}

void MinHeap::remove(int value)
{
	size_t key = find(value);
	if (key == -1)
	{
		std::cout << "Could not remove value: " << value << std::endl;
		return;
	}

	decreaseKey(key, INT_MIN);
	pop();
}

void MinHeap::heapify(size_t index)
{
	size_t leftChild = getLeftChild(index);
	size_t rightChild = getRightChild(index);
	size_t smallest = index;

	if (leftChild < size && heap[leftChild] < heap[smallest])
		smallest = leftChild;
	if (rightChild < size && heap[rightChild] < heap[smallest])
		smallest = rightChild;
	if (smallest != index)
	{
		swap(&heap[index], &heap[smallest]);
		heapify(smallest);
	}
}

size_t MinHeap::find(int value)
{
	for (size_t i = 0; i < size; i++)
	{
		if (heap[i] == value)
			return i;
	}

	return -1;
}

void MinHeap::display()
{
	for (size_t i = 0, lvl = 1; i < size; i++)
	{
		if (i + 1 == lvl)
		{
			lvl *= 2;
			std::cout << std::endl;
		}

		std::cout << heap[i] << " ";
	}

	std::cout << std::endl;
}

void MinHeap::display(int index, int offset)
{
	if (getRightChild(index) < size)
		display(getRightChild(index), offset + 5);
	std::cout << std::setw(offset) << heap[index] << std::endl;
	if (getLeftChild(index) < size)
		display(getLeftChild(index), offset + 5);
}

void MinHeap::displayTree()
{
	if (size != 0)
		display(0, 0);
}

size_t MinHeap::getSize()
{
	return size;
}