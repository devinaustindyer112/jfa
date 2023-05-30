#include "./String/String.h"
#include <iostream>

int main()
{

    String string = String("Hello");
    String string2 = String("World");

    int index = string.indexOf("ell");

    std::cout << index << std::endl;
    return 0;
}