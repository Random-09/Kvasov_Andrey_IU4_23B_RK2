#ifndef RK2_JSON_PARSER_H
#define RK2_JSON_PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include "../cJSON-master/cJSON.h"
#include "database.h"

cJSON *request_json(char *file_path_ptr);

cJSON *get_json_student_array(cJSON *json_object);

void add_students_to_database(cJSON *json_student_array, Student_t *database_ptr, int number_of_students);

#endif
