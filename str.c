#include "./str.h"
#include <stdlib.h>

c_str* string(const char* string, unsigned int len) {
  if(!string) return NULL;
  if(len <= 0) return NULL;

  c_str* p = (c_str*)malloc(sizeof(str));

  // verify length
  unsigned int l = 0;
  while(string[l] != '\0' && l < len) {
    p->str[l] = string[l];
    l++;
  }

  p->len = l;

  return p;
}

unsigned int string_len(c_str* s) {
  if(!s) return -1;
  return s->len;
}

int string_free(c_str* s) {
  if(!s) return -1;
  free(s);
  return 1;
}

int string_copy(c_str* s1, c_str* s2) {
  if(!s1) return -1;
  if(!s2) return -1;

  s2->len = s1->len;
  s2->str = s1->str;

  return 1;
}

const char* string_raw(c_str* s) {
  if(!s) return NULL;
  return s->str;
}

int string_concat_str(c_str* s1, c_str* s2) {
  if(!s1) return -1;
  if(!s2) return -1;
  
  char* tmp = "";
  unsigned int l;

  while(l < s1->len) {
    tmp[l] = s1->str[l];
    l++;
  }

  while((l - s1->len) < s2->len) {
    tmp[(l - s1->len)] = s2->str[(l - s1->len)];
    l++;
  }

  if(l != (s1->len + s2->len)) return -1;

  s1 = string(tmp, l);
  return 1;
}

int string_concat(c_str* s1, const char* s) {
  if(!s1) return -1;

  c_str* s2 = string(s, sizeof(char*));
  return string_concat_str(s1, s2);
}

int string_reverse(c_str* s) {
  if(!s) return -1;
  if(s->len <= 0) return -1;
  
  unsigned int len = s->len;
  char c = '';

  for(unsigned int i = 0; i < (int)(len / 2); i++) {
    c = s->str[i];
    s->str[i] = s->str[len-i];
    s->str[len-i] = c;
  }

  return 1;
}

int string_clear(c_str* s) {
  if(!s) return -1;
  if(s->len <= 0) return;

  s->str[0] = '\0';
  s->len = 0;

  return 0;
}
