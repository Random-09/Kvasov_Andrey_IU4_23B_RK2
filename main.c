#include "json_parser.h"
#include "database.h"
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        puts("Wrong number of arguments");
        exit(EXIT_FAILURE);
    }
    char *file_path = argv[1];
    Student_t *database;
    database = (Student_t *) malloc(DB_CAPACITY * (sizeof(Student_t)));
    int number_of_students = 0;
    json_parser(file_path, database, &number_of_students);
    print_database(database, number_of_students);
}

// TODO
// Узнавать количество студентов из JSON и тогда DB_CAPACITY = число студентов
// Выделить память под указатели на данные студентов
// Сделать файлы stack.c & stack.h, в них функции push_students & pop_students
