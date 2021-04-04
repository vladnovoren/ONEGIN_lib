#include "../include/ONEGIN_strings.hpp"


size_t CntSymb(const char *c_str, const char symb) {
  assert(c_str);

  size_t n_symbs = 0;
  while (c_str++) {
    c_str = strchr(c_str, symb);
    if (c_str)
      n_symbs++;
  }

  return n_symbs;
}


size_t CntStrsWithSymb(StrArr strs, const char symb) {
  assert(strs.arr);

  size_t symb_cnt = 0;
  for (size_t str_num = 0; str_num < strs.n_strs; str_num++)
    symb_cnt += IsSymbFromStr(strs.arr[str_num].c_str, symb);

  return symb_cnt;
}


char *SubStrChr(const char *c_str, const size_t sub_str_len, const char symb) {
  assert(c_str);

  for (size_t pos = 0; pos < sub_str_len; pos++)
    if (c_str[pos] == symb)
      return (char *)c_str + pos;

  return nullptr;
}


bool IsSymbFromStr(const char *c_str, const char symb) {
  assert(c_str);

  return strchr(c_str, symb);
}


size_t SkipSymbols(const char **crg, const char symb) {
  assert(crg);
  assert(*crg);

  size_t n_skipped =0;
  while (**crg && **crg == symb) {
    (*crg)++;
    n_skipped++;
  }

  return n_skipped;
}


size_t SkipSymbols(const char **crg, int (*cmp)(int)) {
  assert(crg);
  assert(*crg);
  assert(cmp);

  size_t n_skipped =0;
  int cur_c = 0;
  while (**crg && cmp(cur_c = **crg)) {
    (*crg)++;
    n_skipped++;
  }

  return n_skipped; 
}
