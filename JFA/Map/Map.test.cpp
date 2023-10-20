#include "./map.hpp"
#include "../json/json_object.hpp"
#include "../json/json_value.hpp"
#include "../jfa_string/jfa_string.hpp"
#include "../../catch_amalgamated.hpp"

TEST_CASE("constructor", "[map]")
{
    Map<int, int> map = Map<int, int>();
    map.put(1, 1);

    Map<JFA::String, JSONValue> map2 = Map<JFA::String, JSONValue>();
    map2.put("Hello", JSONValue("World"));
}