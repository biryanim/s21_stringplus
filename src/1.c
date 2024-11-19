#include "s21_string.h"

int main() {
  char str1[100] = "hello  how,a y. and what, yiu do in this, plase";
  char str2[100] = "hello  how,a y. and what, yiu do in this, plase";
  char delim[100] = " ,.";
  char p_str1[100] = {0};
  char p_str2[100] = {0};
  char *ptr1 = p_str1, *ptr2 = p_str2;
  int k = s21_sprintf(ptr1, "qwe %s qwe", "");

  return 0;
}
