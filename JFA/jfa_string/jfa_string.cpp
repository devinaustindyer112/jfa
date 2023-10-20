#include "../utils/utils.hpp"
#include "jfa_string.hpp"

JFA::String::String()
{
    this->str = nullptr;
}

JFA::String::String(const char *str)
{
    this->str = new char[size(str) + 1];
    for (int i = 0; i < size(str); i++)
    {
        this->str[i] = str[i];
    }
    this->str[size(str)] = '\0';
}

JFA::String::String(const String &other)
{
    if (other.str == nullptr)
    {
        this->str = nullptr;
        return;
    }

    this->str = new char[other.length() + 1];
    for (int i = 0; i < other.length(); i++)
    {
        this->str[i] = other[i];
    }
    this->str[other.length()] = '\0';
}

JFA::String::~String()
{
    if (this->str != nullptr)
    {
        delete[] this->str;
    }
}

JFA::String &JFA::String::operator=(const String &other)
{
    if (this == &other)
    {
        return *this;
    }

    delete[] this->str;

    if (other.str == nullptr)
    {
        this->str = nullptr;
        return *this;
    }

    this->str = new char[other.length() + 1];
    for (int i = 0; i < other.length(); i++)
    {
        this->str[i] = other[i];
    }
    this->str[other.length()] = '\0';
    return *this;
}

JFA::String &JFA::String::operator=(char character)
{
    if (this->str != nullptr)
        delete[] this->str;

    this->str = new char[2];
    this->str[0] = character;
    this->str[1] = '\0';
    return *this;
}

JFA::String JFA::String::operator+(JFA::String string)
{
    int len1 = this->length();
    int len2 = string.length();

    char *str = new char[len1 + len2 + 1];

    for (int i = 0; i < len1; i++)
    {
        str[i] = this->str[i];
    }
    for (int i = 0; i < len2; i++)
    {
        str[i + len1] = string[i];
    }

    str[len1 + len2] = '\0';

    return JFA::String(str);
}

JFA::String JFA::String::operator+(char character)
{
    int len = this->length();
    char *str = new char[len + 2];

    for (int i = 0; i < len; i++)
    {
        str[i] = this->str[i];
    }

    str[len] = character;
    str[len + 1] = '\0';

    return JFA::String(str);
}

char JFA::String::operator[](int index) const
{
    return this->str[index];
}

char JFA::String::operator[](int index)
{
    return this->str[index];
}

char JFA::String::operator==(const char *str)
{
    if (this->length() != size(str))
        return false;

    for (int i = 0; i < this->length(); i++)
    {
        if (this->str[i] != str[i])
        {
            return false;
        }
    }
    return true;
}

char JFA::String::operator==(JFA::String str)
{
    if (this->length() != str.length())
        return false;

    for (int i = 0; i < this->length(); i++)
    {
        if (this->str[i] != str[i])
        {
            return false;
        }
    }
    return true;
}

bool JFA::String::equals(JFA::String str)
{
    if (this->length() != str.length())
        return false;

    for (int i = 0; i < str.length(); i++)
    {
        if (this->str[i] != str[i])
        {
            return false;
        }
    }
    return true;
}

JFA::String JFA::String::substring(int start, int end)
{
    int length = end - start;

    char sub[length + 1];
    for (int i = start; i < end; i++)
    {
        sub[i] = this->str[i + start];
    }
    sub[length] = '\0';

    return JFA::String(sub);
}

JFA::String JFA::String::replace(const char *search, const char *replace)
{
    int index = this->indexOf(search);
    int len = this->length();
    int lenSearch = size(search);
    int lenReplace = size(replace);
    int newLength = len + lenReplace - lenSearch;

    char *str = new char[newLength + 1];

    for (int i = 0; i < index; i++)
    {
        str[i] = this->str[i];
    }
    for (int i = 0; i < lenReplace; i++)
    {
        str[index + i] = replace[i];
    }
    for (int i = index + lenSearch; i < len; i++)
    {
        str[i + lenReplace - lenSearch] = this->str[i];
    }

    str[newLength] = '\0';

    return JFA::String(str);
}

JFA::String JFA::String::replaceAll(const char *search, const char *replace)
{
    JFA::String str = JFA::String(this->str);
    while (str.indexOf(search) != -1)
    {
        str = str.replace(search, replace);
    }
    return str;
}

int JFA::String::length()
{
    return size(this->str);
}

int JFA::String::length() const
{
    return size(this->str);
}

int JFA::String::indexOf(const char *search)
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
