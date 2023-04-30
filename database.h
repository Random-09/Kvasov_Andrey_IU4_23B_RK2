#ifndef RK2_DATABASE_H
#define RK2_DATABASE_H

#include <stdio.h>

#define DB_CAPACITY 50

// id, name, record_book, rating, attendance, login

typedef struct {
    int *student_id;
    char *student_name;
    int *student_record_number;
    double *student_rating;
    int *student_attendance;
    char *student_login;
} Student_t;

void print_database(Student_t *database_ptr, int number_of_students);

//void free_database();

#endif
