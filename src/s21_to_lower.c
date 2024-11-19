#include "s21_string.h"

void *s21_to_lower(const char *str) {
  char *new = s21_NULL;
  if (str) {
    s21_size_t size = s21_strlen(str);
    new = calloc(size, 1);
    if (new) {
      for (s21_size_t i = 0; i < size; i++) {
        if (str[i] >= 65 && str[i] <= 90)
          new[i] = str[i] + 32;
        else
          new[i] = str[i];
      }
    }
  }
  return (void *)new;
}