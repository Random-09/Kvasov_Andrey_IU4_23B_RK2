#include "database.h"

// id, name, record_book, rating, attendance, login

void print_database(Student_t *database_ptr, int number_of_students) {
    for (int i = 0; i < number_of_students; i++) {
        printf("Student with id: %d\nName: %s\nStudent card number: %d\n"
               "Average grade: %.2f\nAttendance: %d\nLogin: %s\n\n",
               *database_ptr[i].student_id, database_ptr[i].student_name, *database_ptr[i].student_record_number,
               *database_ptr[i].student_rating, *database_ptr[i].student_attendance, database_ptr[i].student_login);
    }
}

void free_database(Student_t *database_ptr, int number_of_students) {
    for (int i = 0; i < number_of_students; i++) {
        free(database_ptr[i].student_id);
        free(database_ptr[i].student_name);
        free(database_ptr[i].student_record_number);
        free(database_ptr[i].student_rating);
        free(database_ptr[i].student_attendance);
        free(database_ptr[i].student_login);
    }
    free(database_ptr);
}


//free(p_database[index].id);
//free(p_database[index].name);
//free(p_database[index].student_card_number);
//free(p_database[index].average_grade);
//free(p_database[index].login);
//free(p_database[index].hash);