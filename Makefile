main: Utilities/Utilities.cpp String/String.cpp Main.cpp
	g++ -std=c++14 -o main Utilities/Utilities.cpp String/String.cpp Main.cpp

test-string: catch_amalgamated.cpp Utilities/Utilities.cpp String/String.cpp String/String.Test.cpp
	g++ -std=c++14 -o test-string catch_amalgamated.cpp Utilities/Utilities.cpp String/String.cpp String/String.Test.cpp
	./test-string

test-utils: catch_amalgamated.cpp Utilities/Utilities.cpp Utilities/Utilities.Test.cpp
	g++ -std=c++14 -o test-utils catch_amalgamated.cpp Utilities/Utilities.cpp Utilities/Utilities.Test.cpp
	./test-utils

clean: 
	rm -f test

 