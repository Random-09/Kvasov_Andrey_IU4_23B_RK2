#include <string.h>
#include "json_parser.h"

void json_parser(char *file_path_ptr, Student_t *database_ptr, int *number_of_students) {
    size_t file_len;
    char *buffer;
    FILE *file_ptr = fopen(file_path_ptr, "r");
    if (file_ptr == NULL) {
        puts("Error reading file");
        exit(EXIT_FAILURE);
    }

    fseek(file_ptr, 0, SEEK_END);
    file_len = ftell(file_ptr);
    fseek(file_ptr, 0, SEEK_SET);
    buffer = malloc(sizeof(char) * file_len);
    fread(buffer, sizeof(char), file_len, file_ptr);

    cJSON *json_file = cJSON_Parse(buffer);
    if (json_file == NULL) {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            printf("JSON parsing error: %s\n", error_ptr);
        }
        exit(EXIT_FAILURE);
    }

    cJSON *student_id = NULL;
    cJSON *student_name = NULL;
    cJSON *student_record_number = NULL;
    cJSON *student_rating = NULL;
    cJSON *student_attendance = NULL;
    cJSON *student_login = NULL;
    cJSON *student_array = cJSON_GetObjectItem(json_file, "students");

    for (int i = 0; i < cJSON_GetArraySize(student_array); i++) {
        cJSON *array_item = cJSON_GetArrayItem(student_array, i);
        student_id = cJSON_GetObjectItem(array_item, "student_id");
        student_name = cJSON_GetObjectItem(array_item, "student_name");
        student_record_number = cJSON_GetObjectItem(array_item, "student_record_number");
        student_rating = cJSON_GetObjectItem(array_item, "student_rating");
        student_attendance = cJSON_GetObjectItem(array_item, "student_attendance");
        student_login = cJSON_GetObjectItem(array_item, "student_login");
        Student_t student = {&student_id->valueint,
                             student_name->valuestring,
                             student_record_number->valuestring,
                             &student_rating->valuedouble,
                             &student_attendance->valueint,
                             student_login->valuestring};
        database_ptr[*number_of_students] = student;
        (*number_of_students)++;
    }
}