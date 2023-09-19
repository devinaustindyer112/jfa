#include "String.hpp"
#include "../Utilities/Utilities.hpp"
#include "../catch_amalgamated.hpp"

TEST_CASE("constructors", "[constructors]")
{
    JFA::String str1 = JFA::String();
    REQUIRE(str1.str == nullptr);

    JFA::String str2 = JFA::String("test");
    REQUIRE(strCompare(str2.str, "test"));

    JFA::String *str3 = new JFA::String("test");
    REQUIRE(strCompare(str3->str, "test"));

    delete str3;
}

TEST_CASE("copy constructor", "[copy constructor]")
{
    JFA::String str1 = JFA::String("test");
    JFA::String str2 = JFA::String(str1);

    REQUIRE(strCompare(str2.str, "test"));
}

TEST_CASE("assignment operator", "[assignment operator]")
{
    JFA::String str1 = JFA::String();
    JFA::String str2 = JFA::String("test");

    str1 = str2;

    REQUIRE(strCompare(str2.str, "test"));
}

TEST_CASE("equals", "[equals]")
{
    JFA::String str1 = JFA::String("test");
    JFA::String str2 = JFA::String("test");
    JFA::String str3 = JFA::String("test2");

    REQUIRE(str1.equals(str2) == true);
    REQUIRE(str1.equals(str3) == false);
}

TEST_CASE("substring", "[substring]")
{
    JFA::String str1 = JFA::String("test");
    JFA::String str2 = str1.substring(1, 3);

    REQUIRE(str1.equals(str2) == false);
}

TEST_CASE("length", "[length]")
{
    JFA::String *str1 = new JFA::String("test");
    JFA::String *str2 = new JFA::String("");

    REQUIRE(str1->length() == 4);
    REQUIRE(str2->length() == 0);
}

TEST_CASE("charAt", "[charAt]")
{
    JFA::String *str1 = new JFA::String("test");
    JFA::String *str2 = new JFA::String("");

    REQUIRE(str1->length() == 4);
    REQUIRE(str2->length() == 0);
}

TEST_CASE("operator+", "[operator+]")
{
    JFA::String str1 = JFA::String("test");
    JFA::String str2 = JFA::String("er");

    JFA::String str3 = str1 + str2;

    REQUIRE(str3 == JFA::String("tester"));
}

TEST_CASE("operator+ with char", "[operator+ with char]")
{
    JFA::String str1 = JFA::String("test");
    JFA::String str2 = str1 + 's';

    REQUIRE(str2 == JFA::String("tests"));
}

TEST_CASE("indexOf", "[indexOf]")
{
    JFA::String str = JFA::String("These are a bunch of words.");

    REQUIRE(str.indexOf("bunch") == 12);
    REQUIRE(str.indexOf("are a") == 6);
    REQUIRE(str.indexOf("words.") == 21);
}

TEST_CASE("replace", "[replace]")
{
    JFA::String str = JFA::String("These are a bunch of words.");
    JFA::String replaced = str.replace("bunch", "lot");

    REQUIRE(strCompare(replaced.toCharArray(), "These are a lot of words.") == 1);
}

TEST_CASE("replaceAll", "[replaceAll]")
{
    JFA::String str = JFA::String("These are a bunch of words.");
    JFA::String replaced = str.replaceAll(" ", "");

    REQUIRE(strCompare(replaced.toCharArray(), "Theseareabunchofwords.") == 1);
    REQUIRE(replaced.length() == 22);
}

TEST_CASE("print", "[print]")
{
    JFA::String str = JFA::String("This should print for the world to see.");
    str.print();
}
