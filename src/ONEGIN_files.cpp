#include "../include/ONEGIN_files.hpp"


FILE *OpenFile(const char *file_name, const char *mode) {
	assert(file_name);
	assert(mode);

	FILE *opened_file = fopen(file_name, mode);
	if (!opened_file) {
		printf("Unable to open file \"%s\".\n", file_name);
	}

	return opened_file;
}


size_t SizeOfFile(FILE *file) {
	assert(file);

	fseek(file, 0, SEEK_END);
	size_t file_size = ftell(file);
	fseek(file, 0, SEEK_SET);
	return file_size;
}


size_t SizeOfFile(char const *file_name) {
	assert(file_name);

	struct stat stfile;

	if (stat(file_name, &stfile) == -1){
		return 0;
	} else {
		return stfile.st_size;
	}
}


Str StrArrToStr(StrArr src) {
	Str str = {};

	str.c_str = src.arr[0].c_str;
	str.len   = src.size;
	return str;
}


StrArr StrToStrArr(Str src) {
	assert(src.c_str);

	size_t n_strs = CntSymb(src.c_str, '\n');
	StrArr strs   = AllocStrArr(n_strs);

	if (!strs.n_strs)
		return EMPTY_STR_ARR;

	char *str_begin = src.c_str;
	char *str_end   = nullptr;

	for (size_t str_num = 0; str_num < n_strs; str_num++) {
		str_end = strchr(str_begin, '\n');
		if (!str_end)
	  		return EMPTY_STR_ARR;

		*str_end = '\0';
		strs.arr[str_num] = {str_begin, (size_t)(str_end - str_begin)};
		str_begin = ++str_end;
	}

	strs.size = src.len;
	return strs;
}


Str FileToStr(FILE *src, bool new_line) {
	assert(src);

	size_t buf_size = SizeOfFile(src);
	if (!buf_size) {
		printf("Empty input file.\n");
		return EMPTY_STR;
	}

	char *buf = (char *)calloc(buf_size + 2, sizeof(char));
	if (!buf) {
		printf("Too big input file size.\n");
		return EMPTY_STR;
	}

	size_t fread_cnt = fread(buf, sizeof(char), buf_size, src);
	if (fread_cnt != buf_size) {
		printf("Too big input file size.\n");
		return EMPTY_STR;
	}

	if (new_line && buf[buf_size - 1] != '\n') {
		buf[buf_size] = '\n';
		buf_size++;
	}

	return {buf, buf_size};
}


Str FileToStr(const char *src_name, bool new_line) {
	assert(src_name);

	FILE *src = OpenFile(src_name, "rb");
	if (!src)
		return EMPTY_STR;

	Str str = FileToStr(src, new_line);
	fclose(src);
	return str;
}


StrArr FileToStrArr(FILE *src) {
  assert(src);
 
  Str str = FileToStr(src, true);
  if (!str.len)
    return EMPTY_STR_ARR;

  return StrToStrArr(str);
}


StrArr FileToStrArr(const char *file_name) {
	assert(file_name);

	Str str = FileToStr(file_name, false);
	if (!str.len)
		return EMPTY_STR_ARR;

	return StrToStrArr(str);
}


int StrToFile(FILE *dest, const Str src) {
	assert(src.c_str);

	size_t fwrite_res = fwrite(src.c_str, sizeof(char), src.len, dest);
	if (fwrite_res != src.len) {
		printf("Error writing buf from Str object to file.\n");
		return 1;
	} else {
		return 0;
	}
}


int StrToFile(const char *file_name, const Str src) {
	assert(file_name);

	FILE *dest = OpenFile(file_name, "wb");
	assert(dest);
	return StrToFile(dest, src);
}


int StrArrToFile(FILE *dest, StrArr src) {
	assert(dest);

	Str cur_str = {};
	for (size_t str_num = 0; str_num < src.n_strs; str_num++) {
	    cur_str = src.arr[str_num];
		cur_str.c_str[cur_str.len] = '\n';
	}

	cur_str.c_str = src.arr[0].c_str;
	cur_str.len   = src.size;
	if (!StrToFile(dest, cur_str)) {
		return 1;
	} else {
		return 0;
	}
}


int StrArrToFile(const char *file_name, StrArr src) {
	assert(file_name);

	FILE *dest = OpenFile(file_name, "wb");
	assert(dest);
	return StrArrToFile(dest, src);
}
