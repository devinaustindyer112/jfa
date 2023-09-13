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
        NULL_VALUE,
    };

    Type type;
    JFA::String string;
    JSONObject *object;
    Array<JSONValue> *array;
    JSONValue();
    JSONValue(const JSONValue &other);
    JSONValue &operator=(const JSONValue &other);
    JSONValue(JFA::String value);
    JSONValue(JSONValue *value);
    JSONValue(JSONObject *value);
    JSONValue(Array<JSONValue> *value);
    JSONValue get(JFA::String key);
    JSONValue get(int index);
    ~JSONValue();
    void print();
    bool isNull();
    bool equals(JSONValue *value);
    bool equals(JSONValue value);
};

#endif // JSONVALUE_HPP
