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
    JSONObject(const JSONObject &other);
    JSONObject(String key, JSONValue *value);
    JSONObject(JSONObject *object);
    JSONObject &operator=(const JSONObject &other);
    JSONValue *get(String key);
    ~JSONObject();
    bool equals(JSONObject *object);
    bool equals(JSONObject object);
    void print();
};

#endif // JSONOBJECT_HPP