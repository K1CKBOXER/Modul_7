#include <iostream>
#include <exception>
#include "Arr.h"

using namespace std;

int main() 
{
    Arr array(10);

    try 
    {
        for (int i = 0; i < 10; ++i) 
        {
            array[i] = i + 1;
        }

        array.resize(7);

        array.insertBefore(8, 4);

        array.remove(2);

        array.insertAtEnd(231);

        for (int i = 0; i < array.getLength(); ++i) 
        {
            cout << array[i] << ' ';
        }

    }
    catch (exception& e) 
    {
        e.what();
    }

    return 0;
}
