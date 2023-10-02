#ifndef PARSE_HPP
#define PARSE_HPP
#include "../String/String.hpp"
#include "../Tokenizer/Tokenizer.hpp"
#include "../Array/Array.hpp"
#include "../JSON/JSONValue.hpp"
#include "../JSON/JSONObject.hpp"
#include <iostream>

// Change to JFA
class Parser
{
private:
    Tokenizer tokenizer;
    JSONObject *parseObject();
    Array<JSONValue> parseArray();
    void print();
    void eat(JSONToken::Type type);

public:
    JSONObject *root;
    Parser(JFA::String str);
    ~Parser();
    void parse();
    JSONValue *parseValue();
};

#endif // PARSE_HPP