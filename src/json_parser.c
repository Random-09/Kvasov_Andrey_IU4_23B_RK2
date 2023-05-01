#include <string.h>
#include "../include/json_parser.h"

cJSON *request_json(char *file_path_ptr) {
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
    return json_file;
}

cJSON *get_json_student_array(cJSON *json_object) {
    cJSON *json_student_array = cJSON_GetObjectItem(json_object, "students");
    return json_student_array;
}

void add_students_to_database(cJSON *json_student_array, Student_t *database_ptr, int number_of_students) {
    cJSON *student_id = NULL;
    cJSON *student_name = NULL;
    cJSON *student_record_number = NULL;
    cJSON *student_rating = NULL;
    cJSON *student_attendance = NULL;
    cJSON *student_login = NULL;

    for (int i = 0; i < number_of_students; i++) {
        cJSON *array_item = cJSON_GetArrayItem(json_student_array, i);
        student_id = cJSON_GetObjectItem(array_item, "student_id");
        student_name = cJSON_GetObjectItem(array_item, "student_name");
        student_record_number = cJSON_GetObjectItem(array_item, "student_record_number");
        student_rating = cJSON_GetObjectItem(array_item, "student_rating");
        student_attendance = cJSON_GetObjectItem(array_item, "student_attendance");
        student_login = cJSON_GetObjectItem(array_item, "student_login");
        Student_t student = {&student_id->valueint,
                             student_name->valuestring,
                             &student_record_number->valueint,
                             &student_rating->valuedouble,
                             &student_attendance->valueint,
                             student_login->valuestring};
        database_ptr[i] = student;
    }
}