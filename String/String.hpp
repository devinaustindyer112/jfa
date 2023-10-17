#ifndef STRING_HPP
#define STRING_HPP

namespace JFA
{
    class String
    {
    public:
        char *str;
        String();
        String(const char *str);
        String(const String &str);
        ~String();
        String &operator=(const String &other);
        String &operator=(char character);
        String operator+(String str);
        String operator+(char character);
        char operator[](int index);
        // Required for copy constructor
        char operator[](int index) const;
        char operator==(const char *str);
        char operator==(String str);
        bool equals(String str);
        String substring(int start, int end);
        String replace(const char *search, const char *replace);
        String replaceAll(const char *search, const char *replace);
        int length();
        int length() const;
        int indexOf(const char *search);
    };
}

#endif // STRING_HPP