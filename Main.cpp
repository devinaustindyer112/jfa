#include "./String/String.h"
#include <iostream>

int main()
{

    String string = String("Hello");
    String string2 = String("World");

    String string3 = string + string2;

    for(int i = 0; i < string3.length(); i++)
    {
        std::cout << string3.charAt(i);
    }

    return 0;
}