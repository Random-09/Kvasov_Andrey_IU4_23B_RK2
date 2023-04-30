#ifndef RK2_JSON_PARSER_H
#define RK2_JSON_PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include "cJSON-master/cJSON.h"
#include "database.h"

void json_parser(char *file_path_ptr, Student_t *database_ptr, int *number_of_students);

#endif
