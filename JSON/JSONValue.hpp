#ifndef JSONVALUE_HPP
#define JSONVALUE_HPP
#include "../String/String.hpp"
#include "../Array/Array.hpp"

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
    Array<JSONValue> *array;
    JSONValue();
    JSONValue(String value);
    JSONValue(const JSONValue &value);
    JSONValue(JSONObject *value);
    JSONValue(JSONObject &&value);
    JSONValue(Array<JSONValue> *value);
    JSONValue(Array<JSONValue> &&value);
    ~JSONValue();
    JSONValue &operator=(const JSONValue &value);
    void print();
    void print(int indent);
};

#endif // JSONVALUE_HPP
