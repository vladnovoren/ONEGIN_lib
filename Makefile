CC=g++
CFLAGS=-Wall -Wextra


structs: src/ONEGIN_structs.cpp include/ONEGIN_structs.hpp
	$(CC) -c $(CFLAGS) src/ONEGIN_structs.cpp -o libs/ONEGIN_structs.o


strings: src/ONEGIN_strings.cpp include/ONEGIN_strings.hpp structs
	$(CC) -c $(CFLAGS) src/ONEGIN_strings.cpp -o libs/ONEGIN_strings.o

files: src/ONEGIN_files.cpp include/ONEGIN_files.hpp strings
	$(CC) -c $(CFLAGS) src/ONEGIN_files.cpp -o libs/ONEGIN_files.o
