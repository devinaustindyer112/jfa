#include "String.hpp"
#include "../Utilities/Utilities.hpp"
#include "../catch_amalgamated.hpp"

TEST_CASE("constructors")
{
    JFA::String str1 = JFA::String();
    REQUIRE(str1.str == nullptr);

    JFA::String str2 = JFA::String("test");
    REQUIRE(strCompare(str2.str, "test"));
}

TEST_CASE("copy constructor")
{
    JFA::String str1 = JFA::String("test");
    JFA::String str2 = str1;

    REQUIRE(strCompare(str2.str, "test"));
}

TEST_CASE("assignment operator")
{
    JFA::String str1 = JFA::String();
    JFA::String str2 = JFA::String("test");

    str1 = str2;

    REQUIRE(strCompare(str2.str, "test"));
}

TEST_CASE("operator= char")
{
    JFA::String str = JFA::String();
    str = 'A';

    REQUIRE(str.equals("A"));
}

TEST_CASE("operator+")
{
    JFA::String str1 = JFA::String("test");
    JFA::String str2 = JFA::String("er");

    JFA::String str3 = str1 + str2;

    REQUIRE(str3 == JFA::String("tester"));
}

TEST_CASE("operator+ with char")
{
    JFA::String str1 = JFA::String("test");
    JFA::String str2 = str1 + 's';

    REQUIRE(str2 == JFA::String("tests"));
}

TEST_CASE("operator[]")
{
    JFA::String str = JFA::String("test");
    REQUIRE(str[0] == 't');
    REQUIRE(str[1] == 'e');
    REQUIRE(str[2] == 's');
    REQUIRE(str[3] == 't');
    REQUIRE(str[4] == '\0');
}

TEST_CASE("equals")
{
    JFA::String str1 = JFA::String("test");
    JFA::String str2 = JFA::String("test");
    JFA::String str3 = JFA::String("test2");

    REQUIRE(str1.equals(str2) == true);
    REQUIRE(str1.equals(str3) == false);
}

TEST_CASE("substring")
{
    JFA::String str1 = JFA::String("test");
    JFA::String str2 = str1.substring(1, 3);

    REQUIRE(str1.equals(str2) == false);
}

TEST_CASE("replace")
{
    JFA::String str = JFA::String("These are a bunch of words.");
    JFA::String replaced = str.replace("bunch", "lot");

    REQUIRE(replaced == "These are a lot of words.");
}

TEST_CASE("replaceAll")
{

    JFA::String str = JFA::String("{ \"effect\": \"waves\", \"speed\": \"0.5\", \"color\": \"blue }\"");
    JFA::String replaced = str.replaceAll(" ", "");
    REQUIRE(replaced == "{\"effect\":\"waves\",\"speed\":\"0.5\",\"color\":\"blue}\"");
}

TEST_CASE("length")
{
    JFA::String str1 = JFA::String("test");
    JFA::String str2 = JFA::String("");
    JFA::String str3 = JFA::String();

    REQUIRE(str1.length() == 4);
    REQUIRE(str2.length() == 0);
}

TEST_CASE("indexOf")
{
    JFA::String str = JFA::String("These are a bunch of words.");

    REQUIRE(str.indexOf("bunch") == 12);
    REQUIRE(str.indexOf("are a") == 6);
    REQUIRE(str.indexOf("words.") == 21);
}