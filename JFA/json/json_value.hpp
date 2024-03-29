#ifndef JSONVALUE_HPP
#define JSONVALUE_HPP
#include "../jfa_string/jfa_string.hpp"
#include "../array/array.hpp"

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
    // Forward declaration of JSONObject
    JSONObject *object;
    Array<JSONValue> array;
    JSONValue();
    JSONValue(const JSONValue &other);
    JSONValue(JFA::String value);
    JSONValue(JSONObject value);
    JSONValue(Array<JSONValue> value);
    JSONValue &operator=(const JSONValue &other);
    JSONValue get(JFA::String key);
    JSONValue get(int index);
    ~JSONValue();
    bool operator==(JSONValue other);
    bool isNull();
    void print();
};

#endif // JSONVALUE_HPP
