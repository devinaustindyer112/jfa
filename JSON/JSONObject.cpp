#include "JSONObject.hpp"
#include <iostream>

JSONObject::JSONObject()
{
    this->key = "";
}

// Deep copy
JSONObject::JSONObject(const JSONObject &other)
{
    this->key = other.key;
    this->value = new JSONValue(other.value);
}

JSONObject::JSONObject(String key, JSONValue *value)
{
    this->key = key;
    this->value = new JSONValue(value);
}

JSONObject::JSONObject(JSONObject *object)
{
    this->key = object->key;
    this->value = new JSONValue(object->value);
}

JSONObject::~JSONObject()
{
    std::cout << "Deleting object \n";
    delete this->value;
}

JSONObject &JSONObject::operator=(const JSONObject &other)
{
    if (this != &other)
    {
        this->key = other.key;
        delete this->value;
        this->value = new JSONValue(*other.value);
    }
    return *this;
}

JSONValue *JSONObject::get(String key)
{
    if (this->key.equals(key))
    {
        return this->value;
    }
    else
    {
        return this->value->get(key);
    }
}

bool JSONObject::equals(JSONObject *object)
{
    return this->key.equals(object->key) && this->value->equals(object->value);
}

bool JSONObject::equals(JSONObject object)
{
    return this->key.equals(object.key) && this->value->equals(object.value);
}

void JSONObject::print()
{
    this->key.print();
    std::cout << ": ";
    value->print();
    std::cout << std::endl;
}