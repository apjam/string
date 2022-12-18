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
  s21_sprintf(s, "text: %d", 7);
  printf("%s", s);
  return 0;
}
