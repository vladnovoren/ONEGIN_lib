#ifndef ONEGIN_FILES_HPP
#define ONEGIN_FILES_HPP


#include "ONEGIN_structs.hpp"


FILE   *OpenFile(const char *file_name, const char *mode);

size_t SizeOfFile(FILE *file);

size_t SizeOfFile(char const *file_name);

Str    FileToStr(FILE *src, bool new_line);

Str    FileToStr(char const *file_name, bool new_line);

StrArr FileToStrArr(FILE *src);

StrArr FileToStrArr(const char *file_name);

int    StrToFile(FILE *dest, const Str src);

int    StrArrToFile(FILE *dest, Str src);


#endif /* ONEGIN_files.hpp */
