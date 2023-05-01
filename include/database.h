#ifndef RK2_DATABASE_H
#define RK2_DATABASE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *student_id;
    char *student_name;
    int *student_record_number;
    double *student_rating;
    int *student_attendance;
    char *student_login;
} Student_t;

void print_database(Student_t *database_ptr, int number_of_students);

bool id_in_database(int id, Student_t *database_ptr, int number_of_students);

int id_index(int id, Student_t *database_ptr, int number_of_students);

#endif
