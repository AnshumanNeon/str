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

const char* string_raw(str* s) {
  if(!s) return -1;
  return s->str;
}

int string_concat(str* s1, str* s2) {
  if(!s1) return -1;
  if(!s2) return -1;
  
  char* tmp;
  unsigned int l;

  while(l < s1->len) {
    tmp[l] = s1[l];
    l++;
  }

  while((l - s1->len) < s2->len) {
    tmp[(l - s1->len)] = s2[(l - s1->len)];
    l++;
  }

  if(l != (s1->len + s2->len)) return -1;

  return string(tmp, l);
}

int string_concat(str* s1, const char* string) {
  if(!s1) return -1;

  s2 = string(string, sizeof(char*));
  return string_concat(s1, s2);
}

#define STR_H
#endif
