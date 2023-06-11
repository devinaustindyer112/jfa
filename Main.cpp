#include "String/String.hpp"
#include "Array/Array.hpp"
#include <iostream>

struct JSONToken {
    String token;
    String type;
};

struct JSONNode {
    String token;
    String type;
};

Array<String> tokenize(String json) {
    Array<String> tokens = Array<String>();
    json = json.replaceAll(" ", "");
    for(int i = 0; i < json.length(); i++) {
        if(json.charAt(i) == '{' || json.charAt(i) == '}' || json.charAt(i) == ':' || json.charAt(i) == ',') {
            tokens.push(json.charAt(i));
         } else {
            String token = "";
            while(json.charAt(i)!= '{' && json.charAt(i) != '}' && json.charAt(i) != ':' && json.charAt(i)!= ',' && i < json.length()) {
                token = token + String(json.charAt(i));
                i++;
            }
            tokens.push(token);
            i--;
        }
    }
    return tokens;
}

JSONNode parser(Array<JSONToken>) {
    
}


