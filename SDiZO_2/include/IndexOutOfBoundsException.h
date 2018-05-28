#pragma once
#include <stdexcept>

class IndexOutOfBoundsException :
	public std::runtime_error
{
public:
	IndexOutOfBoundsException(const char* msg) : runtime_error(msg) {}
};