#ifndef JFA_HPP
#define JFA_HPP
#include "../String/String.hpp"
#include "../Array/Array.hpp"

struct JSONNode
{
    String key;
    String value;
    Array<JSONNode> children;
    JSONNode *child;
};

class JFA
{
private:
    String str;
    JSONNode root;

public:
    JFA(String json);
    ~JFA();
    JSONNode operator[](String key);
};

#endif // JFA_HPP