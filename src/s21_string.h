#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>

// удалить и заменить на свою
#include <string.h>

#define s21_size_t unsigned long long
#define s21_NULL (void*)0

#define STAR -1

typedef enum flags_t {
  MINUS, PLUS, SPACE, SHARP, ZERO
} flags_t;

typedef enum length_t {
  h_len, l_len, L_len
} length_t;

typedef struct s21_sprintf_t {
  flags_t flags[5];
  int width;
  int precision;
  length_t length[3];
  char specifier;
} s21_sprintf_t;

s21_size_t s21_strlen(const char *str);
int s21_sprintf(char *str, const char *format, ...);
void parse_format(char **format_string, s21_sprintf_t *s21_sprintf);
void get_flags(char **format_string, flags_t *flags);
void get_width(char **format_string, int *width);
void get_precision(char **format_string, int *precision);
void get_length(char **format_string, length_t *length);
void get_specifier(char **format_string, char *specifier);
void spec_d_i(s21_sprintf_t *s21_string, va_list A, char *str);
int get_number(char c);
void array_to_number(int count, int *buffer, int *x);

#endif  // SRC_S21_STRING_H_