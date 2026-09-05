#ifndef STR_H

struct STR {
  char* str;
  unsigned int len;
};

typedef STR str;

str* string(const char* string, unsigned int len);
unsigned int string_len(str* s);
int string_free(str* s);
int string_copy(str* s1, str* s2);
const char* string_raw(str* s);
int string_concat(str* s1, str* s2);
int string_concat(str* s1, const char* string);

#define STR_H
#endif
