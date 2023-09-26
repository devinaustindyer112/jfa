#ifndef JSONOBJECT_HPP
#define JSONOBJECT_HPP
#include "../String/String.hpp"
#include "JSONValue.hpp"

class JSONObject
{
public:
    JFA::String key;
    JSONValue *value;
    JSONObject();
    JSONObject(const JSONObject &other);
    JSONObject(JFA::String key, JSONValue value);
    JSONObject &operator=(const JSONObject &other);
    JSONValue get(JFA::String key);
    ~JSONObject();
    bool operator==(JSONObject other);
    bool operator==(const JSONObject &object) const;
    void print();
};

#endif // JSONOBJECT_HPP