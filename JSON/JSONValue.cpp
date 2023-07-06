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

JSONValue::JSONValue(JSONValue &&value)
{
    if (value.type == Type::STRING)
    {
        this->type = Type::STRING;
        this->string = value.string;
    }
    else if (value.type == Type::OBJECT)
    {
        this->type = Type::OBJECT;
        this->object = new JSONObject(value.object->key, value.object);
    }
}

JSONValue::~JSONValue()
{
    if (this->type == Type::OBJECT)
    {
        std::cout << "deleting object " << this->object->key.toCharArray() << std::endl;
        delete this->object;
    }
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