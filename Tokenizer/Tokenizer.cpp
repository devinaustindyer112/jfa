#include "Tokenizer.hpp"
#include "String/String.hpp"

Tokenizer::Tokenizer(String str) {
    this->str = str;
    this->index = 0;
}

