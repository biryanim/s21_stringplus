#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *trim = s21_NULL;
  if (!trim_chars || !trim_chars[0]) trim_chars = "\t\n";
  if (src) {
    s21_size_t start = 0;
    s21_size_t end = s21_strlen(src) - 1;
    while (src[start] && s21_strchr(trim_chars, src[start])) start++;
    while (src[end] && s21_strchr(trim_chars, src[end])) end--;
    s21_size_t len_trim = end - start + 2;
    if (len_trim > 0) trim = calloc(len_trim, sizeof(char));
    if (trim) s21_strncpy(trim, &src[start], end - start + 1);
  }
  return (void *)trim;
}