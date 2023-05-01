#include "include/json_parser.h"
#include "include/database.h"
#include "include/stack.h"
#include "cJSON-master/cJSON.h"
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
    int number_of_students = cJSON_GetArraySize(json_student_array);
    database = (Student_t *) malloc(sizeof(Student_t) * number_of_students);
    add_students_to_database(json_student_array, database, number_of_students);
    print_database(database, number_of_students);
    Stack_t *stack_top = NULL;
    push_students(&stack_top, database, number_of_students);
    pop_students(&stack_top);
    free(database);
}
