#include "./json_value.hpp"
#include "./json_object.hpp"
#include "../jfa_string/jfa_string.hpp"
#include "../array/array.hpp"

JSONValue::JSONValue()
{
    this->type = Type::NULL_VALUE;
    this->string = "";
    this->object = nullptr;
    this->array = Array<JSONValue>();
}

// Copy constructor (Deep copy)
JSONValue::JSONValue(const JSONValue &other)
{
    this->type = other.type;
    this->string = other.string;

    if (other.type != Type::OBJECT)
    {
        this->object = nullptr;
    }
    else if (other.type == Type::OBJECT)
    {
        if (other.object != nullptr)
        {
            this->object = new JSONObject(*other.object);
        }
        else
        {
            this->object = nullptr;
        }
    }
    else if (other.type == Type::ARRAY)
    {
        this->array = other.array;
    }
    else if (other.type == Type::NULL_VALUE)
    {
        this->type = Type::NULL_VALUE;
    }
}

// Deep copy assignment operator
JSONValue &JSONValue::operator=(const JSONValue &other)
{
    if (this == &other)
    {
        return *this;
    }

    this->type = other.type;
    this->string = other.string;
    this->array = other.array;

    if (this->object != nullptr)
    {
        delete this->object;
    }

    if (other.object != nullptr)
    {
        this->object = new JSONObject(*other.object);
    }
    else
    {
        this->object = nullptr;
    }

    return *this;
}

// Destructor
JSONValue::~JSONValue()
{
    // I believe the issue is that not all constructors, assignment operator
    // and copy constructor are handling the object correctly. It should
    // be set to nullptr where appropriate.

    if (this->object != nullptr)
    {
        delete this->object;
    }
}

JSONValue::JSONValue(JFA::String string)
{
    this->type = Type::STRING;
    this->string = string;
    this->array = Array<JSONValue>();
    this->object = nullptr;
}

JSONValue::JSONValue(JSONObject object)
{
    this->type = Type::OBJECT;
    this->object = new JSONObject(object);
    this->string = "";
    this->array = Array<JSONValue>();
}

JSONValue::JSONValue(Array<JSONValue> array)
{
    this->type = Type::ARRAY;
    this->object = nullptr;
    this->string = "";
    this->array = array;
}

JSONValue JSONValue::get(JFA::String key)
{
    if (this->type == JSONValue::Type::OBJECT)
    {
        return this->object->get(key);
    }
    else if (this->type == JSONValue::Type::ARRAY)
    {
        JSONValue value;
        int index = 0;
        do
        {
            value = this->array.get(index).get(key);
            index++;
        } while (!value.isNull() && index < this->array.length());
        return value;
    }
    else if (this->type == JSONValue::Type::STRING)
    {
        return this->string;
    }
    else
    {
        return JSONValue();
    }
}

JSONValue JSONValue::get(int index)
{
    if (this->type == JSONValue::Type::ARRAY)
    {
        return this->array.get(index);
    }
    else
    {
        return JSONValue();
    }
}

bool JSONValue::isNull()
{
    return this->type == JSONValue::Type::NULL_VALUE;
}

bool JSONValue::operator==(JSONValue other)
{
    if (this->type == JSONValue::Type::STRING && other.type == JSONValue::Type::STRING)
    {
        return this->string == other.string;
    }
    if (this->type == JSONValue::Type::ARRAY && other.type == JSONValue::Type::ARRAY)
    {
        return this->array == other.array;
    }
    if (this->type == JSONValue::Type::OBJECT && other.type == JSONValue::Type::OBJECT)
    {
        return this->object == other.object;
    }

    return false;
}