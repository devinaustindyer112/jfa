#include "JSONValue.hpp"
#include "JSONObject.hpp"
#include <iostream>

JSONValue::JSONValue()
{
    this->type = Type::STRING;
    this->string = "";
}

JSONValue::JSONValue(String string)
{
    this->type = Type::STRING;
    this->string = string;
}

JSONValue::JSONValue(JSONObject *object)
{
    this->type = Type::OBJECT;
    this->object = new JSONObject(object);
}

JSONValue::JSONValue(const JSONValue &other)
{
    if (other.type == Type::STRING)
    {
        this->type = Type::STRING;
        this->string = other.string;
    }
    else if (other.type == Type::OBJECT)
    {
        this->type = Type::OBJECT;
        this->object = new JSONObject(other.object->key, other.object);
    }
}

JSONValue::JSONValue(JSONObject &&object)
{
    this->type = Type::OBJECT;
    this->object = new JSONObject(object);
}

JSONValue::JSONValue(Array<JSONValue> *other)
{
    // To be implemented
}

JSONValue::JSONValue(Array<JSONValue> &&other)
{
    // To be implemented
}

JSONValue::~JSONValue()
{
    if (this->type == Type::OBJECT)
    {
        delete this->object;
    }
}

JSONValue &JSONValue::operator=(const JSONValue &other)
{
    if (this->type == Type::OBJECT)
    {
        delete this->object;
    }
    if (other.type == Type::STRING)
    {
        this->type = Type::STRING;
        this->string = other.string;
    }
    else if (other.type == Type::OBJECT)
    {
        this->type = Type::OBJECT;
        this->object = new JSONObject(other.object->key, other.object);
    }
    return *this;
}

void JSONValue::print()
{
    if (this->type == JSONValue::Type::STRING)
    {
        std::cout << this->string.toCharArray() << std::endl;
    }
    else if (this->type == JSONValue::Type::OBJECT)
    {
        this->object->print();
    }
}

void JSONValue::print(int indent)
{
    for (int i = 0; i < indent; i++)
    {
        std::cout << "    ";
    }
    if (this->type == JSONValue::Type::STRING)
    {
        std::cout << this->string.toCharArray() << std::endl;
    }
    else if (this->type == JSONValue::Type::OBJECT)
    {
        this->object->print(indent);
    }
}