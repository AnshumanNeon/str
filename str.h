#ifndef STR_H

typedef struct {
  char* str;
  unsigned int len;
} str;

str* string(const char* string, unsigned int len);
unsigned int string_len(str* s);
int string_free(str* s);
int string_copy(str* s1, str* s2);
const char* string_raw(str* s);
int string_concat_str(str* s1, str* s2);
int string_concat(str* s1, const char* s);

#define STR_H
#endif
