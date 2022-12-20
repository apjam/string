#include "s21_string.h"


int s21_sprintf(char *str, const char *format, ...) {
  char *format_string = (char *)format;
  int count = 0;
  s21_sprintf_t s21_sprintf = {0};
  va_list A;
  va_start(A, format);

  // идем по форматной строке посимвольно
  while (*format_string) {
    if (*format_string == '%') {
      parse_format(&format_string, &s21_sprintf);
      //str[count++] = va_arg(A, int) + 48;
    } else {
      //str[count++] = *format_string;
      format_string++;
    }
  }
  va_end(A);
  str[count] = '\0';
  return count;
}

void parse_format(char **format_string, s21_sprintf_t *s21_sprintf) {
  (*format_string)++;

  get_flags(format_string, s21_sprintf->flags);
  //printf("minus:%d\n", s21_sprintf->flags[MINUS]);
  //printf("plus:%d\n", s21_sprintf->flags[PLUS]);
  //printf("space:%d\n", s21_sprintf->flags[SPACE]);
  //printf("sharp:%d\n", s21_sprintf->flags[SHARP]);
  //printf("zero:%d\n", s21_sprintf->flags[ZERO]);

  get_width(format_string, &s21_sprintf->width);
  //printf("width: %d\n", s21_sprintf->width);

  get_precision(format_string, &s21_sprintf->precision);
  //printf("precision: %d\n", s21_sprintf->precision);
  
  get_length(format_string, s21_sprintf->length);
  // printf("h:%d\n", s21_sprintf->length[h_len]);
  // printf("l:%d\n", s21_sprintf->length[l_len]);
  // printf("L:%d\n", s21_sprintf->length[L_len]);

  get_specifier(format_string, &s21_sprintf->specifier);
  //printf("specifier:%c\n", s21_sprintf->specifier);

  (*format_string)++;
}

/* Парсеры */

void get_flags(char **format_string, flags_t *flags) {
  for (int c;;(*format_string)++) {
    c = *(*format_string);
    if (c == '-') flags[MINUS]++;
    else if (c == '+') flags[PLUS]++;
    else if (c == ' ') flags[SPACE]++;
    else if (c == '#') flags[SHARP]++;
    else if (c == '0') flags[ZERO]++;
    else break;
  }
}

void get_width(char **format_string, int *width) {
  int buffer[20] = {0};
  int count = 0;
  for (int c;;(*format_string)++) {
    c = *(*format_string);
    if (c == '*') {
      *width = STAR;
      (*format_string)++;
      break;
    } else if ((buffer[count] = get_number(c)) != -1) {
      count++;
    } else {
      break;
    }
  }
  if (count) array_to_number(count, buffer, width);
}

void get_precision(char **format_string, int *precision) {
  if (*(*format_string) == '.') {
    (*format_string)++;
    if (*(*format_string) == '*') {
      *precision = STAR;
      (*format_string)++;
    } else {
      int buffer[20] = {0};
      int count = 0;
      for (int c;;(*format_string)++) {
        c = *(*format_string);
        if ((buffer[count] = get_number(c)) != -1) {
          count++;
        } else {
          break;
        }
      }
      if (count) array_to_number(count, buffer, precision);
    }
  }
}

void get_length(char **format_string, length_t *length) {
  switch (*(*format_string)) {
    case 'h':
      length[h_len]++;
      (*format_string)++;
      break;
    case 'l':
      length[l_len]++;
      (*format_string)++;
      break;
    case 'L':
      length[L_len]++;
      (*format_string)++;
      break;
    default:
      break;
  }
}

void get_specifier(char **format_string, char *specifier) {
  *specifier = *(strchr("cdifsugGeExXonp", *(*format_string)));
}

/* Выполнение спецификаторов*/

// void spec_d_i(s21_sprintf_t *s21_string, va_list A, char *str) {
//   int value = va_arg(A, int);
// }



/* Вспомогательные функции */

int get_number(char c) {
  return (c >= 48 && c <= 57) ? c - 48 : -1;
}

void array_to_number(int count, int *buffer, int *x) {
  for (int i = count - 1, j = 1; i >= 0; i--, j *= 10)
    *x += buffer[i] * j;
}
