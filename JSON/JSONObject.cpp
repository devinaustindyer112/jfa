#include "JSONObject.hpp"
#include <iostream>

JSONObject::JSONObject()
{
    this->key = "";
    this->value = new JSONValue();
}

JSONObject::JSONObject(String key, JSONValue *value)
{
    this->key = key;
    this->value = value;
}

JSONObject::JSONObject(String key, JSONValue &&value)
{
    if (value.type == JSONValue::Type::OBJECT)
    {
        this->key = key;
        this->value = new JSONValue(value.object);
    }
    else
    {
        this->key = key;
        this->value = new JSONValue(value.string);
    }
}

JSONObject::JSONObject(JSONObject *object)
{
    if (object->value->type == JSONValue::Type::OBJECT)
    {
        this->key = object->key;
        this->value = new JSONValue(object->value->object);
    }
    else
    {
        this->key = object->key;
        this->value = new JSONValue(object->value->string);
    }
}

JSONObject::JSONObject(JSONObject &&object)
{
    if (object.value->type == JSONValue::Type::OBJECT)
    {
        this->key = object.key;
        this->value = new JSONValue(object.value->object);
    }
    else
    {
        this->key = object.key;
        this->value = new JSONValue(object.value->string);
    }
}

JSONObject::~JSONObject()
{
    delete this->value;
}

void JSONObject::print()
{
    std::cout << this->key.toCharArray() << ": ";
    if (this->value->type == JSONValue::Type::STRING)
    {
        std::cout << this->value->string.toCharArray() << std::endl;
    }
    else if (this->value->type == JSONValue::Type::OBJECT)
    {
        std::cout << std::endl;
        this->value->object->print();
    }
}