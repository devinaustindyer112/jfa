# test-parser: catch_amalgamated.cpp Map/Map.cpp JSON/JSONObject.hpp JSON/JSONObject.cpp JSON/JSONValue.cpp JSON/JSONValue.hpp Utilities/Utilities.cpp String/String.cpp Array/Array.cpp Tokenizer/Tokenizer.cpp Parser/Parser.cpp Parser/Parser.Test.cpp
# 	g++ -std=c++14 -o test-parser catch_amalgamated.cpp Map/Map.cpp JSON/JSONObject.cpp JSON/JSONValue.cpp Utilities/Utilities.cpp String/String.cpp Array/Array.cpp Tokenizer/Tokenizer.cpp Parser/Parser.cpp Parser/Parser.Test.cpp
# 	./test-parser

test-parser: catch_amalgamated.cpp JFA/map/map.cpp JFA/map/map.hpp JFA/json/json_value.cpp JFA/json/json_value.hpp JFA/json/json_object.cpp JFA/json/json_object.hpp JFA/utils/utils.cpp JFA/utils/utils.hpp JFA/jfa_string/jfa_string.cpp JFA/jfa_string/jfa_string.hpp JFA/array/array.cpp JFA/array/array.hpp JFA/tokenizer/tokenizer.cpp JFA/tokenizer/tokenizer.hpp JFA/parser/parser.cpp JFA/parser/parser.hpp JFA/parser/parser.test.cpp
	g++ -std=c++14 -o test-parser catch_amalgamated.cpp JFA/map/map.cpp JFA/json/json_value.cpp JFA/json/json_object.cpp JFA/utils/utils.cpp JFA/jfa_string/jfa_string.cpp JFA/array/array.cpp JFA/tokenizer/tokenizer.cpp JFA/parser/parser.cpp JFA/parser/parser.test.cpp
	./test-parser


clean: 
	rm -f test-*

 