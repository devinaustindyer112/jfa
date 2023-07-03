#include "Parser/Parser.hpp"
#include "catch_amalgamated.hpp"
#include <iostream>

int main()
{
    Parser parser = Parser("{\"key\": \"value\"}");
    parser.parse();
    parser.print();
    return 0;
}
