#include "Arr.h"
#include "error.h"

Arr::Arr(int length) : m_length(length) 
{
	if (length <= 0) 
	{
		throw error_range();
	}
	else 
	{
		m_data = new int[length];
	}
}
Arr::Arr(const Arr& a) 
{
	locate(a.getLength());

	for (int index = 0; index < m_length; ++index) 
	{
		m_data[index] = a.m_data[index];
	}
}

Arr& Arr::operator = (const Arr& a) 
{
	if (&a == this) 
	{
		return *this;
	}

	locate(a.getLength());

	for (int index = 0; index < m_length; ++index) 
	{
		m_data[index] = a.m_data[index];
	}

	return *this;
}

void Arr::erase() 
{
	delete[] m_data;
	m_data = nullptr;
	m_length = 0;
}

int& Arr::operator[](int index) 
{
	if (index >= 0 && index < m_length) 
	{
		return m_data[index];
	}
}

int Arr::getLength() const 
{
	return m_length;
}

void Arr::locate(int newLength) 
{
	erase();

	if (newLength <= 0) 
	{
		return;
	}

	m_data = new int[newLength];
	m_length = newLength;
}

void Arr::resize(int newLength) 
{
	if (newLength == m_length) 
	{
		return;
	}

	if (newLength <= 0) 
	{
		erase();
		return;
	}

	int* data = new int[newLength];

	if (m_length > 0) 
	{
		int elementsToCopy = (newLength > m_length) ? m_length : newLength;

		for (int index = 0; index < elementsToCopy; ++index) 
		{
			data[index] = m_data[index];
		}

		delete[] m_data;

		m_data = data;
		m_length = newLength;
	}
}

void Arr::insertBefore(int value, int index) {
	if (index <= 0 && index >= m_length) {
		throw error_length();
	};

	int* data = new int[m_length + 1];

	for (int before = 0; before < index; ++before) 
	{
		data[before] = m_data[before];
	}

	data[index] = value;

	for (int after = index; after < m_length; ++after) 
	{
		data[after + 1] = m_data[after];
	}

	delete[] m_data;
	m_data = data;
	++m_length;
}

void Arr::remove(int index) 
{
	if (index <= 0 && index >= m_length) 
	{
		throw error_length();
	};

	if (m_length == 1) 
	{
		erase();
		return;
	}

	int* data = new int[m_length - 1];

	for (int before = 0; before < index; ++before) 
	{
		data[before] = m_data[before];
	}

	for (int after = index + 1; after < m_length; ++after) 
	{
		data[after - 1] = m_data[after];
	}

	delete[] m_data;
	m_data = data;
	--m_length;
}


void Arr::insertAtEnd(int value) 
{
	insertBefore(value, m_length);
}