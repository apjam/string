#include "s21_string.h"


int s21_sprintf(char *str, const char *format, ...) {
  char *format_temp = (char *)format;
  int count = 0;
  va_list A;
  va_start(A, format);

  // идем по строке формата
  while (*format_temp) {
    if (*format_temp == '%') {
      get_format(*(format_temp + 1));
      str[count++] = va_arg(A, int) + 48;
    } else {
      str[count++] = *format_temp;
    }
    format_temp++;
  }
  va_end(A);
  str[count] = '\0';
  return count;

  // static char s_str[11] = "hello world";
  // str = s_str;
}

int get_format(char ch) {
  int count = 0;
  // if (get_flag)
  // if (wigth)
  // if (tochnost')
  // if (lenght)
  if (get_spec(ch)) {
    count++;
  }
  return count;
  // add to array and get argement from ... and manipulation on number
}

// bool get_flag(char *flag) {
//   bool flag = true;
//   if (flag == '-') {

//   } else if (flag == '+') {

//   } else if (flag == ' ') {

//   } else if (flag == '#') {
    
//   } else if (flag == '0') {

//   } else {
//     flag = false;
//   }
//   return flag;
// }

// bool get_width(char ch) {
//   bool flag = true;
//   if (get_number(ch) != -1) {

//   } else if (ch == '*') {

//   } else {
//     flag = false;
//   }
//   return flag;
// }

bool get_spec(char ch) {
  bool flag = false;
  char spec[] = "cdifsu";
  for (char *i = spec;*i;i++) {
    if (*i == ch) {
      flag = true;
    }
  }
  return flag;
}


int get_number(char ch) {
  int x;
  if (ch >= 48 && ch <= 57) {
    x = ch - 48;
  } else {
    x = -1;
  }
  return x;
}