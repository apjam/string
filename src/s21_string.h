#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>

typedef long unsigned s21_size_t;

s21_size_t s21_strlen(const char *str);
int s21_sprintf(char *str, const char *format, ...);
int get_format(char ch);
bool get_spec(char ch);
int get_number(char ch);

#endif  // SRC_S21_STRING_H_