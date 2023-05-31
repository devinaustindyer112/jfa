#include "./String/String.h"
#include <iostream>

int main()
{
    const char* chars = "{key: 'value'}";

    String str1 = String("{key: 'value'}");
    String str2 = str1.replaceAll("'", "");

    std::cout << str2.toCharArray() << std::endl;
    return 0;
}