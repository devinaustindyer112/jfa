#ifndef STRING_HPP
#define STRING_HPP

class String
{
private:
    const char *str;

public:
    String(const char *str);
    String(char character);
    String();
    ~String();

    String substring(int start, int end);
    String replace(const char* search, const char* replace);
    String replaceAll(const char* search, const char* replace);
    String operator+(String str);
    String operator+(char character);
    char operator[](int index);
    const char* toCharArray();
    int length();
    int indexOf(const char* search);
    bool equals(String str);
};

#endif // STRING_HPP