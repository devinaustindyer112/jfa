#ifndef PARSE_HPP
#define PARSE_HPP
#include "../jfa_string/jfa_string.hpp"
#include "../tokenizer/tokenizer.hpp"
#include "../json/json_value.hpp"
#include "../json/json_object.hpp"

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