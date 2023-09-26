#include "JSONObject.hpp"
#include <iostream>

JSONObject::JSONObject()
{
    this->key = "";
    this->value = nullptr;
}

// Copy constructor (Deep copy)
JSONObject::JSONObject(const JSONObject &other)
{
    this->key = other.key;
    if (other.value == nullptr)
    {
        this->value = nullptr;
    }
    else
    {
        this->value = new JSONValue(*other.value);
    }
}

// Deep copy assignment operator
JSONObject &JSONObject::operator=(const JSONObject &other)
{
    if (other.value == nullptr)
    {
        this->value = nullptr;
    }
    else if (this != &other)
    {
        this->key = other.key;
        delete this->value;
        this->value = new JSONValue(*other.value);
    }
    return *this;
}

// Destructor
JSONObject::~JSONObject()
{
    delete this->value;
}

JSONObject::JSONObject(JFA::String key, JSONValue value)
{
    this->key = key;
    this->value = new JSONValue(value);
}

JSONValue JSONObject::get(JFA::String key)
{
    if (this->key == key)
    {
        return *this->value;
    }
    else
    {
        return this->value->get(key);
    }
}

bool JSONObject::operator==(JSONObject object)
{
    if (this->value == nullptr && object.value == nullptr)
    {
        return true;
    }
    return this->key == object.key && *this->value == *object.value;
}

void JSONObject::print()
{
    this->key.print();
    std::cout << ": ";
    value->print();
    std::cout << std::endl;
}