#include "JSONObject.hpp"
#include <iostream>

JSONObject::JSONObject()
{
    this->key = "";
    this->value = JSONValue();
}

JSONObject::JSONObject(String key, JSONValue value)
{
    this->key = key;
    this->value = value;
}

JSONObject::~JSONObject()
{
}

void JSONObject::print()
{
    std::cout << this->key.toCharArray() << ": ";
    if (this->value.type == JSONValue::Type::STRING)
    {
        std::cout << this->value.string.toCharArray() << std::endl;
    }
    else if (this->value.type == JSONValue::Type::OBJECT)
    {
        std::cout << std::endl;
        this->value.object->print();
    }
}