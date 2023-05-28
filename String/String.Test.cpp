#include "String.h"
#include "../catch_amalgamated.hpp"

TEST_CASE("substring", "[substring]")
{
    String str1 = String("test");
    String str2 = String("es");
    REQUIRE(str1.equals(str2) == false);
}

TEST_CASE("equals", "[equals]")
{
    String str1 = String("test");
    String str2 = String("test");
    String str3 = String("false");

    REQUIRE(str1.equals(str2) == true);
    REQUIRE(str1.equals(str3) == false);
}

TEST_CASE("length", "[length]")
{
    String *str1 = new String("test");
    String *str2 = new String("");

    REQUIRE(str1->length() == 4);
    REQUIRE(str2->length() == 0);
}

TEST_CASE("charAt", "[charAt]")
{
    String *str1 = new String("test");
    String *str2 = new String("");

    REQUIRE(str1->length() == 4);
    REQUIRE(str2->length() == 0);
}

TEST_CASE("operator+", "[operator+]")
{
    String str1 = String("test");
    String str2 = String("er");

    String str3 =  str1 + str2;

    REQUIRE(str3.equals(String("tester")) == true);
}
