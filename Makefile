main: Utilities/Utilities.cpp Tokenizer/Tokenizer.cpp String/String.cpp Array/Array.cpp Main.cpp
	g++ -std=c++14 -o main Utilities/Utilities.cpp Tokenizer/Tokenizer.cpp String/String.cpp Main.cpp Array/Array.cpp

test-string: catch_amalgamated.cpp Utilities/Utilities.cpp String/String.cpp String/String.Test.cpp
	g++ -std=c++14 -o test-string catch_amalgamated.cpp Utilities/Utilities.cpp String/String.cpp String/String.Test.cpp
	./test-string

test-utils: catch_amalgamated.cpp Utilities/Utilities.cpp Utilities/Utilities.Test.cpp
	g++ -std=c++14 -o test-utils catch_amalgamated.cpp Utilities/Utilities.cpp Utilities/Utilities.Test.cpp
	./test-utils

test-array: catch_amalgamated.cpp Utilities/Utilities.cpp String/String.cpp Array/Array.cpp Array/Array.Test.cpp
	g++ -std=c++14 -o test-array catch_amalgamated.cpp Utilities/Utilities.cpp String/String.cpp Array/Array.cpp Array/Array.Test.cpp
	./test-array

test-tokenizer: catch_amalgamated.cpp Utilities/Utilities.cpp String/String.cpp Array/Array.cpp Tokenizer/Tokenizer.cpp Tokenizer/Tokenizer.Test.cpp
	g++ -std=c++14 -o test-tokenizer catch_amalgamated.cpp Utilities/Utilities.cpp String/String.cpp Array/Array.cpp Tokenizer/Tokenizer.cpp Tokenizer/Tokenizer.Test.cpp
	./test-tokenizer

clean: 
	rm -f test-*

 