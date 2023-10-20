#include "./Map.hpp"
#include "../JSON/JSONObject.hpp"
#include "../JSON/JSONValue.hpp"
#include "../String/String.hpp"
#include "../catch_amalgamated.hpp"

TEST_CASE("constructor", "[map]")
{
    Map<int, int> map = Map<int, int>();
    map.put(1, 1);

    Map<JFA::String, JSONValue> map2 = Map<JFA::String, JSONValue>();
    map2.put("Hello", JSONValue("World"));
}