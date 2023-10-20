#ifndef JSONOBJECT_HPP
#define JSONOBJECT_HPP
#include "./json_value.hpp"
#include "../jfa_string/jfa_string.hpp"
#include "../map/map.hpp"

class JSONObject
{
public:
    Map<JFA::String, JSONValue> entries;
    JSONObject();
    JSONObject(const JSONObject &other);
    JSONObject(JFA::String key, JSONValue value);
    JSONObject &operator=(const JSONObject &other);
    JSONValue get(JFA::String key);
    bool operator==(const JSONObject &object) const;
};

#endif // JSONOBJECT_HPP