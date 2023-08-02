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

JSONValue::JSONValue(JSONValue *value)
{
    if (value->type == Type::OBJECT)
    {
        this->type = Type::OBJECT;
        this->object = new JSONObject(value->object);
    }
    else if (value->type == Type::ARRAY)
    {
        this->type = Type::ARRAY;
        this->array = new Array<JSONValue>(value->array);
    }
    else
    {
        this->type = Type::STRING;
        this->string = value->string;
    }
}

JSONValue::JSONValue(JSONObject *object)
{
    this->type = Type::OBJECT;
    this->object = new JSONObject(object);
}

JSONValue::JSONValue(Array<JSONValue> *array)
{
    this->type = Type::ARRAY;
    this->array = new Array<JSONValue>(array);
}

JSONValue::~JSONValue()
{
    if (this->type == Type::OBJECT)
    {
        delete this->object;
    }
}

void JSONValue::print()
{
    if (this->type == JSONValue::Type::OBJECT)
    {
        this->object->print();
    }
    else if (this->type == JSONValue::Type::ARRAY)
    {
        this->array->print();
    }
    else if (this->type == JSONValue::Type::STRING)
    {
        this->string.print();
    }
    std::cout << std::endl;
}