1. Сборка Makefile состоит из 3х частей:
  -s21_string.a: Создание библиотеки из объектных файлов, ranlib
  -test: Сборка файлов для тестов 
  -gcov_report: генерация html файла

2. В папке src обязательно нахождение файлов:
  -s21_string.h
  -s21_string.a
  -Makefile
  -остальные *.c *.h
  
3. Сложные функции:
  Из базовых 20ти:
  -14. char *strerror(int errnum)
  -20. char *strtok(char *str, const char *delim)
  Из дополнительных:
  -3. void *insert(const char *src, const char *str, size_t start_index)
  -sscanf

4. Полезности
  -Препроцессор для определения ОС для разного поведения программы на mac и linux
  -Дебагер lldb для vscode
  -Asan для gcc
  -80%+ - успешная сдача проекта

5. Тестирование
  -Библиотека модульного тестирования check
  -Написать тесты для каждой функции, для каждого поведения
  -Строчка для прохождения на утечки, запускается в мейне файла тестс srunner_set_fork_status(sr, CK_NOFORK);
  -Docker CMD ["./test_s21_test.sh"]