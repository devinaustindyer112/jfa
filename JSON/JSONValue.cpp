#include "JSONValue.hpp"
#include "JSONObject.hpp"
#include <iostream>

JSONValue::JSONValue()
{
    this->type = Type::STRING;
    this->string = "";
}

// Deep copy
JSONValue::JSONValue(const JSONValue &other)
{
    this->type = other.type;
    this->string = other.string; // Assuming String has a proper copy constructor

    if (other.type == Type::OBJECT)
    {
        this->object = new JSONObject(*other.object); // Deep copy JSONObject
    }
    else if (other.type == Type::ARRAY)
    {
        this->array = new Array<JSONValue>(*other.array); // Deep copy Array<JSONValue>
    }
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
    else if (value->type == Type::STRING)
    {
        this->type = Type::STRING;
        this->string = value->string;
    }
    else if (value->type == Type::ARRAY)
    {
        this->type = Type::ARRAY;
        this->array = new Array<JSONValue>(value->array);
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

JSONValue &JSONValue::operator=(const JSONValue &other)
{
    if (this != &other)
    {
        this->type = other.type;
        this->string = other.string; // Assuming String has a proper copy constructor

        // Delete the existing memory (if applicable)
        if (this->type == Type::OBJECT)
        {
            delete this->object;
        }
        else if (this->type == Type::ARRAY)
        {
            delete this->array;
        }

        // Perform a deep copy of data members
        if (other.type == Type::OBJECT)
        {
            this->object = new JSONObject(*other.object); // Deep copy JSONObject
        }
        else if (other.type == Type::ARRAY)
        {
            this->array = new Array<JSONValue>(*other.array); // Deep copy Array<JSONValue>
        }
    }
    return *this;
}

JSONValue *JSONValue::get(String key)
{
    if (this->type == JSONValue::Type::OBJECT)
    {
        return this->object->get(key);
    }
    else if (this->type == JSONValue::Type::ARRAY)
    {
        //=========
        // This needs to be fixed
        //=========
        return this->array->get(0).get(key);
    }
    return nullptr;
}

void JSONValue::print()
{
    if (this->type == JSONValue::Type::OBJECT)
    {
        this->object->print();
    }
    else if (this->type == JSONValue::Type::STRING)
    {
        this->string.print();
    }
    else if (this->type == JSONValue::Type::ARRAY)
    {
        std::cout << "printing array";
        this->array->print();
    }
}

bool JSONValue::equals(JSONValue *value)
{
    if (this->type == JSONValue::Type::STRING && value->type == JSONValue::Type::STRING)
    {
        return this->string.equals(value->string);
    }
    if (this->type == JSONValue::Type::ARRAY && value->type == JSONValue::Type::ARRAY)
    {
        return this->array->equals(value->array);
    }
    if (this->type == JSONValue::Type::OBJECT && value->type == JSONValue::Type::OBJECT)
    {
        return this->object->equals(value->object);
    }
    return false;
}

bool JSONValue::equals(JSONValue value)
{
    if (this->type == JSONValue::Type::STRING && value.type == JSONValue::Type::STRING)
    {
        return this->string.equals(value.string);
    }
    if (this->type == JSONValue::Type::ARRAY && value.type == JSONValue::Type::ARRAY)
    {
        return this->array->equals(value.array);
    }
    if (this->type == JSONValue::Type::OBJECT && value.type == JSONValue::Type::OBJECT)
    {
        return this->object->equals(value.object);
    }
    return false;
}
