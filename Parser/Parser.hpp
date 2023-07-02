#ifndef PARSE_HPP
#define PARSE_HPP
#include "../String/String.hpp"
#include "../Tokenizer/Tokenizer.hpp"
#include "../Array/Array.hpp"
#include <iostream>

struct JSONObject;

struct JSONValue
{
    enum class Type
    {
        OBJECT,
        ARRAY,
        STRING,
    };

    Type type;
    String string;
    JSONObject *object;

    JSONValue()
    {
        this->type = Type::STRING;
        this->string = "";
    }

    JSONValue(Type type, String string)
    {
        this->type = type;
        this->string = string;
    }

    JSONValue(Type type, JSONObject *object)
    {
        this->type = type;
        this->object = object;
    }
};

struct JSONObject
{
    String key;
    JSONValue value;

    JSONObject()
    {
        this->key = "";
        this->value = JSONValue();
    }

    JSONObject(String key, JSONValue value)
    {
        this->key = key;
        this->value = value;
    }
};

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
    String print();
};

#endif // PARSE_HPP