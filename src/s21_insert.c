#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *insert = s21_NULL;
  s21_size_t len_src = s21_strlen(src);
  s21_size_t len_str = s21_strlen(str);
  if (src && str && start_index <= len_src) {
    s21_size_t len_insert = len_src + len_str + 1;
    insert = calloc(len_insert, sizeof(char));
    for (s21_size_t i = 0; i < start_index; i++) insert[i] = src[i];
    s21_strncat(insert, str, len_str);
    for (s21_size_t i = (start_index + len_str); i < len_insert; i++) {
      insert[i] = src[start_index];
      start_index++;
    }
  }
  return (void *)insert;
}