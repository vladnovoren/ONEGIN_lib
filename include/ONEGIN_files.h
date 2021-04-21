#ifndef ONEGIN_FILES_H
#define ONEGIN_FILES_H


#include "ONEGIN_structs.h"
#include "ONEGIN_strings.h"
#include <sys/stat.h>


FILE   *OpenFile(const char *file_name, const char *mode);


size_t SizeOfFile(FILE *file);

size_t SizeOfFile(char const *file_name);


Str    StrArrToStr(StrArr src);

StrArr StrToStrArr(Str src);


Str    FileToStr(FILE *src, bool new_line);

Str    FileToStr(char const *file_name, bool new_line);


StrArr FileToStrArr(FILE *src);

StrArr FileToStrArr(const char *file_name);


int    StrToFile(FILE *dest, const Str src);

int    StrToFile(const char *file_name, const Str src);

int    StrArrToFile(FILE *dest, StrArr src);

int    StrArrToFile(const char *file_name, StrArr src);


#endif /* ONEGIN_files.h */

