#include "../String/String.hpp"

class Tokenizer
{
private:
    String str;
    int index;
public:
    Tokenizer(String str);
    ~Tokenizer();
    String nextToken();
    bool hasMoreTokens();
};

