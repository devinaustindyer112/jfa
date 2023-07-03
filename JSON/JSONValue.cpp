#include "JSONValue.hpp"
#include "JSONObject.hpp"
#include <iostream>

JSONValue::JSONValue()
{
    this->type = Type::STRING;
    this->string = "";
}

JSONValue::JSONValue(Type type, String string)
{
    this->type = type;
    this->string = string;
}

JSONValue::JSONValue(Type type, JSONObject *object)
{
    this->type = type;
    this->object = object;
}

JSONValue::~JSONValue()
{
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