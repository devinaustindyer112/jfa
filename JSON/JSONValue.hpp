#ifndef JSONVALUE_HPP
#define JSONVALUE_HPP
#include "../String/String.hpp"

class JSONObject;

class JSONValue
{
public:
    enum class Type
    {
        OBJECT,
        ARRAY,
        STRING,
    };

    Type type;
    String string;
    JSONObject *object;

    JSONValue();
    JSONValue(String string);
    JSONValue(JSONObject *object);
    JSONValue(JSONValue &&value);
    ~JSONValue();
    void print();
};

#endif // JSONVALUE_HPP
