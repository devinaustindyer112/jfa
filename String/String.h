#ifndef STRING_H
#define STRING_H

class String
{
private:
    const char *str;

public:
    String(const char *str);
    String();
    ~String();

    String substring(int start, int end);
    String operator+(String str);
    char charAt(int index);
    const char* toCharArray();
    int length();
    int indexOf(char* search);
    bool equals(String str);
};

String concat(String str1, String str2);

#endif // STRING_H