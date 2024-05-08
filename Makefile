
test-parser: catch_amalgamated.cpp jfa/map/map.cpp jfa/map/map.hpp jfa/json/json_value.cpp jfa/json/json_value.hpp jfa/json/json_object.cpp jfa/json/json_object.hpp jfa/utils/utils.cpp jfa/utils/utils.hpp jfa/jfa_string/jfa_string.cpp jfa/jfa_string/jfa_string.hpp jfa/array/array.cpp jfa/array/array.hpp jfa/tokenizer/tokenizer.cpp jfa/tokenizer/tokenizer.hpp jfa/parser/parser.cpp jfa/parser/parser.hpp jfa/parser/parser.test.cpp
	g++ -std=c++14 -o test-parser catch_amalgamated.cpp jfa/map/map.cpp jfa/json/json_value.cpp jfa/json/json_object.cpp jfa/utils/utils.cpp jfa/jfa_string/jfa_string.cpp jfa/array/array.cpp jfa/tokenizer/tokenizer.cpp jfa/parser/parser.cpp jfa/parser/parser.test.cpp
	./test-parser

test-tokenizer: catch_amalgamated.cpp jfa/map/map.cpp jfa/map/map.hpp jfa/json/json_value.cpp jfa/json/json_value.hpp jfa/json/json_object.cpp jfa/json/json_object.hpp jfa/utils/utils.cpp jfa/utils/utils.hpp jfa/jfa_string/jfa_string.cpp jfa/jfa_string/jfa_string.hpp jfa/array/array.cpp jfa/array/array.hpp jfa/tokenizer/tokenizer.cpp jfa/tokenizer/tokenizer.hpp  jfa/tokenizer/tokenizer.test.cpp
	g++ -std=c++14 -o test-tokenizer catch_amalgamated.cpp jfa/map/map.cpp jfa/json/json_value.cpp jfa/json/json_object.cpp jfa/utils/utils.cpp jfa/jfa_string/jfa_string.cpp jfa/array/array.cpp jfa/tokenizer/tokenizer.cpp jfa/tokenizer/tokenizer.test.cpp
	./test-tokenizer

clean: 
	rm -f test-*

 