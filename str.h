#ifndef STR_H
#include <stdlib.h>

struct STR {
  char* str;
  unsigned int len;
};

typedef STR str;

str* string(const char* string, unsigned int len) {
  if(!s) return -1;
  if(len < 0) return -1;

  str* p = (str*)malloc(sizeof(str));

  // verify length
  int l = 0;
  while(string[l] != "\0") {
    l++;
  }

  if(l > len) l = len;

  p->len = l;

  // put string to p
  for(int i = 0; i < p->len; i++) {
    p->str[i] = string[i];
  }

  return *p;
}

unsigned int string_len(str* s) {
  if(!s) return -1;
  return s->len;
}

int string_free(str* s) {
  if(!s) return -1;
  free(s);
  return 1;
}

int string_copy(str* s1, str* s2) {
  if(!s1) return -1;
  if(!s2) return -1;

  s2->len = s1->len;
  s2->str = s1->str;
}

#define STR_H
#endif
