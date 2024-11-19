#include "s21_string.h"

//функция возвращает длину строки
s21_size_t s21_strlen(const char *str) {
  s21_size_t lenght = 0;
  while (*str != 0) lenght++, str++;
  return lenght;
}
//функция возвращает указатель на позицию на которой находиться символ
void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *p = str;
  int flag = 0;
  if (s21_strlen(str) < n) n = s21_strlen(str);
  while (n--) {
    if (*p == c) {
      flag = 1;
      break;  //возвращает адрес первого вхождение в строку символа (с)
    }
    p++;
  }
  return flag ? (void *)p : s21_NULL;
}
// cравнение двух блоков памяти <0 >0 0
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int result = 0;
  const char *str_1 = str1, *str_2 = str2;
  while (n--) {
    if (*str_1 != *str_2) {
      result = *str_1 - *str_2;
      break;
    }
    str_1++, str_2++;
  }
  return result;
}
//копирует из срц в дест n  символов
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  const char *str_in = src, *str_out = dest;
  while (n > 0) {
    *(char *)dest = *str_in;
    dest++, str_in++, n--;
  }
  return (void *)str_out;
}
//заполняем массив указанными символами н раз
void *s21_memset(void *str, int c, s21_size_t n) {
  char *p_str = str;
  int flag = 0;
  while (n > 0) {
    *(char *)str = c;
    str++, n--, flag = 1;
  }
  str = p_str;
  return flag ? (void *)str : s21_NULL;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *str_in = (char *)src, *str_rem = (char *)dest;
  while (*dest != '\0') dest++;
  while (n--) *dest = *str_in, str_in++, dest++;
  *dest = '\0';
  dest = str_rem;
  return dest;
}
char *s21_strchr(const char *str, int c) {
  char *ptr = (char *)str;
  int flag = 0;
  s21_size_t size = s21_strlen(str) + 1;
  while (size-- && !flag) {
    if (*ptr == c) {
      flag = 1;
      break;
    }
    ptr++;
  }
  return flag ? (char *)ptr : s21_NULL;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int result = 0;
  const char *str_1 = str1, *str_2 = str2;
  while (n-- > 0) {
    if (*str_1 != *str_2) {
      result = *str_1 - *str_2;
      break;
    }
    str_1++, str_2++;
  }
  return result;
}
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *src_res = (char *)src, *dest_res = dest;
  int flag = 0;
  while (n > 0) {
    if (*src_res == '\0') flag = 1;
    if (!flag)
      *dest = *src_res;
    else
      *dest = '\0';
    n--, src_res++, dest++;
  }
  return dest_res;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  const char *ret = s21_NULL;
  const char *p1 = str1;
  int match = 0;
  while (*p1 != '\0' && !match) {
    const char *p2 = str2;
    while (*p2 != '\0' && !match) {
      if (*p1 == *p2) match = 1, ret = p1;
      p2++;
    }
    p1++;
  }
  return (char *)ret;
}

char *s21_strrchr(const char *str, int c) {
  char *in_str = (char *)str, *buff = s21_NULL;
  int flag = 0;
  while (*in_str != '\0') {
    if (*in_str == c) {
      buff = in_str;
      flag = 1;
    }
    in_str++;
  }

  return !flag ? s21_NULL : buff;
}

char *s21_strstr(const char *haystack, const char *needle) {
  char *out_str = (char *)haystack, *in_str = (char *)needle;
  char *first_char = out_str;
  int flag = 0, num_char = 0;
  while (*out_str != '\0') {
    if (*out_str == *in_str) {
      first_char = out_str;
      while (*out_str != '\0') {
        if (*out_str == *in_str) num_char++;
        out_str++, in_str++;
      }
      if ((int)s21_strlen(needle) != num_char) {
        num_char = 0;
        in_str = (char *)needle;
        out_str = first_char;
      }
    }
    out_str++;
  }
  flag = (int)s21_strlen(needle) == num_char;
  if (s21_strlen(haystack) == 0) flag = 1;
  if (s21_strlen(needle) == 0) flag = 1;
  return !flag ? s21_NULL : first_char;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  char *p_str = s21_strpbrk(str1, str2);
  int lenght = s21_strlen(str1);
  if (p_str != s21_NULL) lenght = s21_strlen(str1) - s21_strlen(p_str);
  return lenght;
}

char *s21_strtok(char *str, const char *delim) {
  static char *last;
  char *string = str;

  char *p_str = s21_NULL;
  if (string == s21_NULL)  //
    string = last;

  if (string != s21_NULL) {
    p_str = s21_strpbrk(string, delim);
    //первое вхождение
    while (p_str == string) {
      string++;
      p_str = s21_strpbrk(string, delim);

      if (p_str != s21_NULL) {
        *p_str = 0;
        last = p_str + 1;
      }
    }
    if (p_str != s21_NULL) {
      *p_str = 0;
      last = p_str + 1;
    }
  }
  if (p_str == s21_NULL) {
    p_str = last;
    last = s21_NULL;
  }

  return p_str != s21_NULL ? string : s21_NULL;
}

s21_size_t s21_strcspn_n(int n, const char *str1, const char *str2) {
  char *p_str = s21_strpbrk(str1, str2);
  int lenght = s21_strlen(str1);
  if (p_str != s21_NULL) {
    lenght = s21_strlen(str1) - s21_strlen(p_str);
  }
  return n < lenght ? n : lenght;
}
