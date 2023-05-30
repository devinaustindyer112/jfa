#include "../Utilities/Utilities.h"
#include "String.h"
#include <iostream>

// Utility functions

String::String(const char *str)
{
    this->str = str;
}

String::~String()
{
    // No need to free memory, as it is a const char.
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

char String::charAt(int index)
{
    return this->str[index];
}

int String::length()
{
    return size(this->str);
}

String String::operator+(String string)
{
    int len1 = size(this->str); 
    int len2 = string.length();

    char* str = new char[len1 + len2];

    for (int i = 0; i < len1; i++)
    {
        str[i] = this->str[i];
    }
    for (int i = 0; i < len2; i++)
    {
        str[i + len1] = string.charAt(i);
    }

    return String(str);
}

bool String::equals(String str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (this->charAt(i) != str.charAt(i))
        {
            return false;
        }
    }
    return true;
}

const char* String::toCharArray()
{
    const char *str = this->str;
    return str;
}

int String::indexOf(const char* search)
{
    for(int i = 0; i < this->length(); i++) {
        int index = 0;
        while (this->charAt(i) == search[index]) {
            if (index == size(search) - 1) {
                return i - index;
            }
            index++;
            i++;
        }
    }
    return -1;
}