#include "String.h"
#include "../Utilities/Utilities.h"
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

TEST_CASE("indexOf", "[indexOf]") {
    String str = String("These are a bunch of words.");

    REQUIRE(str.indexOf("bunch") == 12);
    REQUIRE(str.indexOf("are a") == 6);
    REQUIRE(str.indexOf("words.") == 21);
}

TEST_CASE("replace", "[replace]") {
    String str = String("These are a bunch of words.");
    String replaced = str.replace("bunch", "lot");

    REQUIRE(strCompare(replaced.toCharArray(),"These are a lot of words.") == 1);
}

TEST_CASE("replaceAll", "[replaceAll]") {
    String str = String("These are a bunch of words.");
    String replaced = str.replaceAll(" ", "_");

    REQUIRE(strCompare(replaced.toCharArray(),"These_are_a_bunch_of_words.") == 1);
}
