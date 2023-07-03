#ifndef JSONOBJECT_HPP
#define JSONOBJECT_HPP
#include "../String/String.hpp"
#include "JSONValue.hpp"

class JSONObject
{
public:
    String key;
    JSONValue value;

    JSONObject();
    JSONObject(String key, JSONValue value);
    ~JSONObject();
    void print();
};

#endif // JSONOBJECT_HPP