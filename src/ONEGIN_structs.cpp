#include "../include/ONEGIN_structs.hpp"



Str AllocStr(const size_t len) {
    if (!len) {
        return EMPTY_STR;
    }

    Str str = {};
    str.c_str = (char *)calloc(len + 1, sizeof(char));
    assert(str.c_str);
    str.len = len;
    return str;
}


void DestructStr(Str *str) {
    assert(str);

    free(str->c_str);
}


StrArr AllocStrArr(const size_t n_strs) {
  if (!n_strs)
    return EMPTY_STR_ARR;

  StrArr str_arr = {};
  str_arr.n_strs = n_strs;
  str_arr.arr = (Str *)calloc(n_strs, sizeof(Str));
  assert(str_arr.arr);
  return str_arr;
}


void DestructStrArr(StrArr *str_arr) {
  assert(str_arr);

  if (str_arr->n_strs) {
    DestructStr(str_arr->arr);
    free(str_arr->arr);
  }
}
