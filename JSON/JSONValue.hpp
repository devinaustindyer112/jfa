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

    // Make thise private?

    Type type;
    String string;
    JSONObject *object;
    Array<JSONValue> *array;
    JSONValue();
    JSONValue(const JSONValue &other);
    JSONValue(String value);
    JSONValue(JSONValue *value);
    JSONValue(JSONObject *value);
    JSONValue(Array<JSONValue> *value);
    JSONValue *get(String key);
    ~JSONValue();
    void print();
    bool equals(JSONValue *value);
    bool equals(JSONValue value);
};

#endif // JSONVALUE_HPP
