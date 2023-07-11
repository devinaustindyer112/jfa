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
    JSONValue(String string);
    JSONValue(const JSONValue &other);
    JSONValue(JSONObject *object);
    JSONValue(JSONObject &&object);
    JSONValue(Array<JSONValue> *other);
    JSONValue(Array<JSONValue> &&other);
    ~JSONValue();
    JSONValue &operator=(const JSONValue &other);
    void print();
    void print(int indent);
};

#endif // JSONVALUE_HPP
