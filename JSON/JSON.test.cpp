#include "./JSONObject.hpp"
#include "./JSONValue.hpp"
#include "../Array/Array.hpp"
#include "../catch_amalgamated.hpp"
#include <iostream>

TEST_CASE("object", "[object]")
{
    JSONValue *val = new JSONValue("bar");
    JSONObject *obj = new JSONObject("foo", val);
    obj->print();

    /* Need to take a step back. Had to delete a bunch of work that I did
            because 99% of it was done without designing or thoughtful consideration.
            I should start testing and working on arrays the next time I work on this. Just worry
            about getting it working with pointer and new.

            Once I start thinking about how I will use these classes in the future I will
            start worrying about what constructors methods and variations of those I need to implement.
            But to start I need to get it working the way I know it will.
    */
}