#ifndef PARSE_HPP
#define PARSE_HPP
#include "../String/String.hpp"
#include "../Tokenizer/Tokenizer.hpp"
#include "../Array/Array.hpp"
#include "../JSON/JSONValue.hpp"
#include "../JSON/JSONObject.hpp"

// Change to JFA
class Parser
{
private:
    Tokenizer *tokenizer;
    void eat(JSONToken::Type type);

public:
    JSONObject root;
    Parser(JFA::String str);
    ~Parser();
    void parse();
    JSONValue parseValue();
    JSONObject parseObject();
};

#endif // PARSE_HPP