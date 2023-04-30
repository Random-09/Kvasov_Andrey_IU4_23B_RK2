#include <string.h>
#include "json_parser.h"

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

int get_number_of_students(cJSON *student_array) {
    return cJSON_GetArraySize(student_array);
}

void add_students_to_database(cJSON *json_student_array, Student_t *database_ptr, int number_of_students) {
    char *student_name_val, *student_login_val;
    for (int i = 0; i < number_of_students; i++) {
        char *student_name, *student_login;
        int *student_id, *student_record_number, *student_attendance;
        double *student_rating;

        student_id = (int *) malloc(sizeof(int));
        student_record_number = (int *) malloc(sizeof(int));
        student_attendance = (int *) malloc(sizeof(int));
        student_rating = (double *) malloc(sizeof(double));

        cJSON *array_item = cJSON_GetArrayItem(json_student_array, i);
        *student_id = cJSON_GetObjectItem(array_item, "student_id")->valueint;
        student_name_val = cJSON_GetObjectItem(array_item, "student_name")->valuestring;
        *student_record_number = cJSON_GetObjectItem(array_item, "student_record_number")->valueint;
        *student_rating = cJSON_GetObjectItem(array_item, "student_rating")->valueint;
        *student_attendance = cJSON_GetObjectItem(array_item, "student_attendance")->valueint;
        student_login_val = cJSON_GetObjectItem(array_item, "student_login")->valuestring;

        student_name = (char *) malloc(sizeof(char) * strlen(student_name_val));
        student_login = (char *) malloc(sizeof(char) * strlen(student_login_val));
        strcpy(student_name, student_name_val);
        strcpy(student_login, student_login_val);

        Student_t student = {student_id, student_name, student_record_number, student_rating,
                             student_attendance, student_login};

        database_ptr[i] = student;
    }
}