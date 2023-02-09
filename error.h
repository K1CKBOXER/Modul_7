#pragma once
#include <exception>

using namespace std;

class error_range : public exception 
{
public:
	virtual const char* what() const noexcept override 
	{
		return "Invalid number";
	}
};

class error_length : public exception 
{
public:
	virtual const char* what() const noexcept override 
	{
		return "Elements out of control";
	}
};