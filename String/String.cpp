#include "../Utilities/Utilities.hpp"
#include "String.hpp"
#include <iostream>

String::String()
{
    this->str = nullptr;
}

String::String(const char *str)
{
    char *newStr = new char[size(str)];
    for (int i = 0; i < size(str); i++)
    {
        newStr[i] = str[i];
    }
    this->str = newStr;
}

String::String(const String &other)
{
    char *newStr = new char[other.length()];
    for (int i = 0; i < other.length(); i++)
    {
        newStr[i] = other[i];
    }
    this->str = newStr;
}

String::~String()
{
    delete[] this->str;
}

String String::substring(int start, int end)
{
    int length = end - start;

    char sub[length];
    for (int i = start; i < end; i++)
    {
        sub[i] = this->str[i + start];
    }

    return String(sub);
}

int String::length()
{
    return size(this->str);
}

int String::length() const
{
    return size(this->str);
}

String String::operator+(String string)
{
    int len1 = size(this->str);
    int len2 = string.length();

    char *str = new char[len1 + len2];

    for (int i = 0; i < len1; i++)
    {
        str[i] = this->str[i];
    }
    for (int i = 0; i < len2; i++)
    {
        str[i + len1] = string[i];
    }

    return String(str);
}

String String::operator+(char character)
{
    int len1 = size(this->str);
    char *str = new char[len1 + 1];

    for (int i = 0; i < len1; i++)
    {
        str[i] = this->str[i];
    }

    str[len1] = character;
    return String(str);
}

String &String::operator=(const String &other)
{
    if (other.str == nullptr)
    {
        std::cout << "IT EQUALS NULL" << std::endl;

        // THIS FIXES THE TESTS BUT IS NOT THE RIGHT WAY TO HANDLE THIS
        // NEED TO FIGURE OUT HOW TO HANDLE THIS APPROPRIATELY

        // THIS WAS MY FIRST ATTEMPT
        // this->str = nullptr;

        return *this;
    }
    else
    {
        std::cout << "HHEEEERRRREEE" << std::endl;

        char *newStr = new char[other.length()];
        for (int i = 0; i < other.length(); i++)
        {
            newStr[i] = other[i];
        }
        delete[] this->str;

        this->str = newStr;
        return *this;
    }
}

char String::operator[](int index) const
{
    return this->str[index];
}

char String::operator[](int index)
{
    return this->str[index];
}

char String::operator==(const char *str)
{
    for (int i = 0; i < this->length(); i++)
    {
        if (this->str[i] != str[i])
        {
            return false;
        }
    }
    return true;
}

bool String::equals(String str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (this->str[i] != str[i])
        {
            return false;
        }
    }
    return true;
}

const char *String::toCharArray()
{
    const char *str = this->str;
    return str;
}

int String::indexOf(const char *search)
{
    for (int i = 0; i < this->length(); i++)
    {
        int index = 0;
        while (this->str[i] == search[index])
        {
            if (index == size(search) - 1)
            {
                return i - index;
            }
            index++;
            i++;
        }
    }
    return -1;
}

String String::replace(const char *search, const char *replace)
{
    int index = this->indexOf(search);
    int len = this->length();
    int lenSearch = size(search);
    int lenReplace = size(replace);

    char *str = new char[len + lenReplace - lenSearch];

    for (int i = 0; i < index; i++)
    {
        str[i] = this->str[i];
    }
    for (int i = 0; i < lenReplace; i++)
    {
        str[i + index] = replace[i];
    }
    for (int i = index + lenSearch; i < len; i++)
    {
        str[i + lenReplace - lenSearch] = this->str[i];
    }

    return String(str);
}

String String::replaceAll(const char *search, const char *replace)
{
    String str = String(this->str);
    while (str.indexOf(search) != -1)
    {
        str = str.replace(search, replace);
    }
    return str;
}

void String::print()
{
    for (int i = 0; i < this->length(); i++)
    {
        std::cout << this->str[i];
    }
}