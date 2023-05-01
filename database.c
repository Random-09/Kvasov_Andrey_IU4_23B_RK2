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

void get_students_ids(Student_t *database_ptr, int *student_ids_ptr, int number_of_students) {
    for (int i = 0; i < number_of_students; i++) {
        student_ids_ptr[i] = *database_ptr[i].student_id;
    }
}

int id_index(int id, Student_t *database_ptr, int number_of_students) {
    for (int i = 0; i < number_of_students; i++) {
        if (*database_ptr[i].student_id == id)
            return i;
    }
    return -1;
}


//free(p_database[index].id);
//free(p_database[index].name);
//free(p_database[index].student_card_number);
//free(p_database[index].average_grade);
//free(p_database[index].login);
//free(p_database[index].hash);