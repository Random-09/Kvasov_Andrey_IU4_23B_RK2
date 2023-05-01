#include "../include/database.h"

void print_database(Student_t *database_ptr, int number_of_students) {
    for (int i = 0; i < number_of_students; i++) {
        printf("Student with id: %d\nName: %s\nStudent card number: %d\n"
               "Average grade: %.2f\nAttendance: %d\nLogin: %s\n\n",
               *database_ptr[i].student_id, database_ptr[i].student_name, *database_ptr[i].student_record_number,
               *database_ptr[i].student_rating, *database_ptr[i].student_attendance, database_ptr[i].student_login);
    }
}

bool id_in_database(int id, Student_t *database_ptr, int number_of_students) {
    return id_index(id, database_ptr, number_of_students) != -1;
}

int id_index(int id, Student_t *database_ptr, int number_of_students) {
    for (int i = 0; i < number_of_students; i++) {
        if (*database_ptr[i].student_id == id)
            return i;
    }
    return -1;
}
