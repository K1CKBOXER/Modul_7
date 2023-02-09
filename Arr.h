#pragma once
#include <exception>

class Arr 
{
private:
	int m_length = 0;
	int* m_data = 0;

public:
	Arr() = default;
	Arr(int length);
	Arr(const Arr& a);

	~Arr() 
	{
		delete[] m_data;
	}

	Arr& operator = (const Arr& a);

	void erase();

	int& operator[](int index);

	int getLength() const;

	void locate(int newLength);

	void resize(int newLength);

	void insertBefore(int value, int index);

	void remove(int index);

	void insertAtEnd(int value);
};