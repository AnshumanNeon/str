#ifndef C_STR_H

typedef struct {
  char* str;
  unsigned int len;
} c_str;

c_str* string(const char* string, unsigned int len);
unsigned int string_len(c_str* s);
int string_free(c_str* s);
int string_copy(c_str* s1, c_str* s2);
const char* string_raw(c_str* s);
int string_concat_str(c_str* s1, c_str* s2);
int string_concat(c_str* s1, const char* s);

#define C_STR_H
#endif
