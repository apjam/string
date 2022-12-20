#include "tests/s21_tests.h"

int main(void) {
  // SRunner *suite_runner = srunner_create(suite_part_1());
  // int failed_count = 0;

  // srunner_run_all(suite_runner, CK_NORMAL);

  // failed_count = srunner_ntests_failed(suite_runner);
  // srunner_free(suite_runner);

  // printf("\n");
  // if (failed_count != 0) 
  //   printf("EXIT_FAILURE");
  // else
  //   printf("EXIT_SUCCESS");

  char s[200];
  char s2[200];
  s21_sprintf(s, "text: %.*ld", 7);
  sprintf(s2, "text: %d\n", 72);
  //printf("%s", s2);
  return 0;
}
