main: JSON/JSONObject.hpp JSON/JSONObject.cpp JSON/JSONValue.cpp JSON/JSONValue.hpp Utilities/Utilities.cpp Tokenizer/Tokenizer.cpp String/String.cpp Array/Array.cpp Main.cpp
	g++ -std=c++14 -o main JSON/JSONObject.cpp JSON/JSONValue.cpp Array/Array.cpp Utilities/Utilities.cpp Tokenizer/Tokenizer.cpp String/String.cpp Main.cpp

test-utils: Utilities/Utilities.cpp Utilities/Utilities.Test.cpp
	g++ -std=c++14 -o test-utils catch_amalgamated.cpp Utilities/Utilities.cpp Utilities/Utilities.Test.cpp
	./test-utils

test-string: Utilities/Utilities.cpp String/String.cpp String/String.Test.cpp
	g++ -std=c++14 -o test-string catch_amalgamated.cpp Utilities/Utilities.cpp String/String.cpp String/String.Test.cpp
	./test-string

test-array: JSON/JSONObject.hpp JSON/JSONObject.cpp JSON/JSONValue.cpp JSON/JSONValue.hpp Utilities/Utilities.cpp String/String.cpp Array/Array.cpp Map/Map.cpp Array/Array.Test.cpp
	g++ -std=c++14 -o test-array catch_amalgamated.cpp JSON/JSONObject.cpp JSON/JSONValue.cpp Utilities/Utilities.cpp String/String.cpp Array/Array.cpp Map/Map.cpp Array/Array.Test.cpp
	./test-array

test-map: JSON/JSONObject.hpp JSON/JSONObject.cpp JSON/JSONValue.cpp JSON/JSONValue.hpp Utilities/Utilities.cpp String/String.cpp Array/Array.cpp Map/Map.cpp Map/Map.Test.cpp
	g++ -std=c++14 -o test-map catch_amalgamated.cpp JSON/JSONObject.cpp JSON/JSONValue.cpp Utilities/Utilities.cpp String/String.cpp Array/Array.cpp Map/Map.cpp Map/Map.Test.cpp
	./test-map

test-json-value: catch_amalgamated.cpp Utilities/Utilities.cpp String/String.cpp Array/Array.cpp Map/Map.cpp JSON/JSONValue.cpp JSON/JSONObject.cpp JSON/JSONValue.Test.cpp
	g++ -std=c++14 -o test-json-value catch_amalgamated.cpp Utilities/Utilities.cpp String/String.cpp Array/Array.cpp Map/Map.cpp JSON/JSONValue.cpp JSON/JSONObject.cpp JSON/JSONValue.Test.cpp
	./test-json-value

test-json-object: catch_amalgamated.cpp Utilities/Utilities.cpp String/String.cpp Array/Array.cpp Map/Map.cpp JSON/JSONValue.cpp JSON/JSONObject.cpp JSON/JSONObject.Test.cpp
	g++ -std=c++14 -o test-json-object catch_amalgamated.cpp Utilities/Utilities.cpp String/String.cpp Array/Array.cpp Map/Map.cpp JSON/JSONValue.cpp JSON/JSONObject.cpp JSON/JSONObject.Test.cpp
	./test-json-object

test-tokenizer: catch_amalgamated.cpp JSON/JSONObject.hpp JSON/JSONObject.cpp JSON/JSONValue.cpp JSON/JSONValue.hpp Utilities/Utilities.cpp String/String.cpp Array/Array.cpp Tokenizer/Tokenizer.cpp Tokenizer/Tokenizer.Test.cpp
	g++ -std=c++14 -o test-tokenizer catch_amalgamated.cpp JSON/JSONObject.cpp JSON/JSONValue.cpp Utilities/Utilities.cpp String/String.cpp Array/Array.cpp Tokenizer/Tokenizer.cpp Tokenizer/Tokenizer.Test.cpp
	./test-tokenizer

test-parser: catch_amalgamated.cpp JSON/JSONObject.hpp JSON/JSONObject.cpp JSON/JSONValue.cpp JSON/JSONValue.hpp Utilities/Utilities.cpp String/String.cpp Array/Array.cpp Tokenizer/Tokenizer.cpp Parser/Parser.cpp Parser/Parser.Test.cpp
	g++ -std=c++14 -o test-parser catch_amalgamated.cpp JSON/JSONObject.cpp JSON/JSONValue.cpp Utilities/Utilities.cpp String/String.cpp Array/Array.cpp Tokenizer/Tokenizer.cpp Parser/Parser.cpp Parser/Parser.Test.cpp
	./test-parser

clean: 
	rm -f test-*

 