#include "s21_tests.h"

// START_TEST(memchr_test_1) {
//   /* Исходный код теста. */
// }
// END_TEST

// START_TEST(memchr_test_2) {
//   /* Исходный код теста. */
// }
// END_TEST

START_TEST(memcmp_test_1) {
  char a[] = "123";
  char b[] = "123456";
  size_t n = 3;
  ck_assert_int_eq(memcmp(a, b, n), 0);
}
END_TEST

START_TEST(memcmp_test_2) {
  char a[] = "123";
  char b[] = "123456";
  size_t n = 4;
  ck_assert_int_eq(memcmp(a, b, n), -1);
}
END_TEST

Suite *suite_part_1(void) {
  Suite *suite = suite_create("Part_1");
  TCase *tcase_core = tcase_create("memchr");
  
  // tcase_add_test(tcase_core, memchr_test_1);
  // tcase_add_test(tcase_core, memchr_test_2);

  tcase_add_test(tcase_core, memcmp_test_1);
  tcase_add_test(tcase_core, memcmp_test_2);
  
  suite_add_tcase(suite, tcase_core);
    
  return suite;
}
