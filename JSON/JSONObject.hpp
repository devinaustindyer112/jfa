#ifndef JSONOBJECT_HPP
#define JSONOBJECT_HPP
#include "../String/String.hpp"
#include "JSONValue.hpp"

class JSONObject
{
public:
    String key;
    JSONValue *value;
    JSONObject();
    JSONObject(JSONObject &object);
    JSONObject(String key, JSONValue *value);
    JSONObject(String key, JSONValue &&value);
    JSONObject(JSONObject *object);
    JSONObject(JSONObject &&object);
    ~JSONObject();
    JSONObject &operator=(const JSONObject &other);
    void print();
    void print(int indent);
};

#endif // JSONOBJECT_HPP