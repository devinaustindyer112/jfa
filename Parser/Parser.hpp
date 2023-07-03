#ifndef PARSE_HPP
#define PARSE_HPP
#include "../String/String.hpp"
#include "../Tokenizer/Tokenizer.hpp"
#include "../Array/Array.hpp"
#include "../JSON/JSONValue.hpp"
#include "../JSON/JSONObject.hpp"
#include <iostream>

class Parser
{
private:
    Tokenizer tokenizer;
    JSONObject root;
    Array<JSONObject *> *objects;
    Array<JSONValue *> *values;

    JSONObject *parseObject();
    Array<JSONValue> parseArray();

    void eat(JSONToken::Type type);

public:
    Parser(String str);
    ~Parser();
    void parse();
    void print();
};

#endif // PARSE_HPP