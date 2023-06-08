#include "String/String.hpp"
#include "Array/Array.hpp"
#include <iostream>

int main()
{
    String str = "{key: 'value'}";
    String trimmed = str.replaceAll(" ", "");
    Array<String> tokens = Array<String>();

    for(int i = 0; i < trimmed.length(); i++) {
        if(trimmed.charAt(i) == '{' || trimmed.charAt(i) == '}' || trimmed.charAt(i) == ':' || trimmed.charAt(i) == ',') {
            tokens.push(trimmed.charAt(i));
         } else {
            String token = "";
            while(trimmed.charAt(i)!= '{' && trimmed.charAt(i) != '}' && trimmed.charAt(i) != ':' && trimmed.charAt(i)!= ',' && i < trimmed.length()) {
                token = token + String(trimmed.charAt(i));
                i++;
            }
            tokens.push(token);
            i--;
        }
    }

    for(int i = 0; i < tokens.length(); i++) {
        std::cout << tokens[i].toCharArray()  << std::endl;
    }
}

