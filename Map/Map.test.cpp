#include "./Map.hpp"
#include "../JSON/JSONObject.hpp"
#include "../JSON/JSONValue.hpp"
#include "../String/String.hpp"
#include "../catch_amalgamated.hpp"

TEST_CASE("constructor")
{
    Map<int, int> map = Map<int, int>();
    REQUIRE(map.getSize() == 0);
}

TEST_CASE("get")
{
    Map<int, int> map = Map<int, int>();
    map.put(1, 2);
    REQUIRE(map.get(1) == 2);

    Map<JFA::String, JFA::String> map2 = Map<JFA::String, JFA::String>();
    map2.put("hello", "world");
    REQUIRE((map2.get("hello") == "world"));

    Map<JFA::String, JSONValue> map3 = Map<JFA::String, JSONValue>();
    map3.put("hello", JSONValue("world"));
    REQUIRE((map3.get("hello") == JSONValue("world")));
    REQUIRE(!(map3.get("hello") == JSONValue("foo")));
}

TEST_CASE("put")
{
    Map<int, int> map = Map<int, int>();
    map.put(1, 2);
    REQUIRE(map.get(1) == 2);
    map.put(1, 3);
    REQUIRE(map.get(1) == 3);
    map.put(2, 4);
    REQUIRE(map.get(2) == 4);
    REQUIRE(map.getSize() == 2);
}
