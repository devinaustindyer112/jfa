#ifndef STRING_HPP
#define STRING_HPP

class String
{
private:
    const char *str;

public:
    //==================
    // Update this to not use const char *str.
    // Need better understanding of c-strings and such.
    // https://stackoverflow.com/questions/6823249/what-is-a-char
    //==================
    String();
    String(const char *str);
    String(const String &str);
    ~String();
    String substring(int start, int end);
    String replace(const char *search, const char *replace);
    String replaceAll(const char *search, const char *replace);
    String operator+(String str);
    String operator+(char character);
    char operator[](int index);
    char operator[](int index) const;
    char operator==(const char *str);
    const char *toCharArray();
    int length();
    int length() const;
    int indexOf(const char *search);
    bool equals(String str);
    void print();
};

#endif // STRING_HPP