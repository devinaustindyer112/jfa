#include "JFA.hpp"
#include "../String/String.hpp"
#include "../Tokenizer/Tokenizer.hpp"

JFA::JFA(String json)
{
    Tokenizer tokenizer(json);
    while (tokenizer.hasNext())
    {
    }
}

// DOCUMENT

// LBRACE (need better names for these)

// RBRACE

// KEY

// VALUE

// COLON
