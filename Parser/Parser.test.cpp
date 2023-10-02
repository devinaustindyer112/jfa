#include "./Parser.hpp"
#include "../String/String.hpp"
#include "../catch_amalgamated.hpp"

TEST_CASE("parse - simple object")
{
    Parser parser = Parser("{ \"effect\":\"waves\" }");

    if (parser.root.get("effect") == JFA::String("wave"))
        std::cout << "Success!\n";
    else
        std::cout << "Failure!\n";
}

TEST_CASE("parse - object with array ")
{
    Parser parser = Parser("{ \"effect\":\"wave\", \"color\":\"blue\" }");

    // parser.root.get("color").print();
}