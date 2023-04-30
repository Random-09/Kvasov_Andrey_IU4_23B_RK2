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
    cJSON *json_object = request_json(file_path);
    cJSON *json_student_array = get_json_student_array(json_object);
    int number_of_students = get_number_of_students(json_student_array);
    database = (Student_t *) malloc(sizeof(Student_t) * number_of_students);
    add_students_to_database(json_student_array, database, number_of_students);
    print_database(database, number_of_students);
//    free_database();                                                        // <---- TO DO
}

// TODO
// Сделать файлы stack.c & stack.h, в них функции push_students & pop_students
