#include "Tokenizer/Tokenizer.hpp"
#include "catch_amalgamated.hpp"
#include <iostream>

int main()
{
    Tokenizer tokenizer = Tokenizer("{\"Value\": \"Hello World\"}");

    while (tokenizer.hasNext())
    {
        JSONToken token = tokenizer.next();

        switch (token.type)
        {
        case JSONToken::Type::STRING:
            std::cout << "STRING" << std::endl;
            break;
        case JSONToken::Type::LBRACE:
            std::cout << "LBRACE" << std::endl;
            break;
        case JSONToken::Type::RBRACE:
            std::cout << "RBRACE" << std::endl;
            break;
        case JSONToken::Type::COLON:
            std::cout << "COLON" << std::endl;
            break;
        case JSONToken::Type::COMMA:
            std::cout << "COMMA" << std::endl;
            break;
        default:
            break;
        }

        std::cout << token.value.toCharArray() << std::endl;
    }
}

// #include "String/String.hpp"
// #include "Array/Array.hpp"
// #include <iostream>

// struct JSONToken {
//     String token;
//     String type;
// };

// struct JSONNode {
//     String token;
//     String type;
// };

// Array<String> tokenize(String json) {
//     Array<String> tokens = Array<String>();
//     json = json.replaceAll(" ", "");
//     for(int i = 0; i < json.length(); i++) {
//         if(json.charAt(i) == '{' || json.charAt(i) == '}' || json.charAt(i) == ':' || json.charAt(i) == ',') {
//             tokens.push(json.charAt(i));
//          } else {
//             String token = "";
//             while(json.charAt(i)!= '{' && json.charAt(i) != '}' && json.charAt(i) != ':' && json.charAt(i)!= ',' && i < json.length()) {
//                 token = token + String(json.charAt(i));
//                 i++;
//             }
//             tokens.push(token);
//             i--;
//         }
//     }
//     return tokens;
// }

// JSONNode parser(Array<JSONToken>) {

// }
