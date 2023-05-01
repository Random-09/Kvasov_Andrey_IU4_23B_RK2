#include "../include/stack.h"

void push_students(Stack_t **stack_top, Student_t *database_ptr, int number_of_students) {
    puts("Enter students' IDs'");
    int *ids_in_stack = (int *) malloc(number_of_students * sizeof(int));
    for (int i = 0; i < number_of_students; i++) {
        int input_attempts = 0;
        int student_id;
        do {
            if (input_attempts > 0)
                puts("This id is already in stack or not in DB, try again.");
            scanf("%d", &student_id);
            input_attempts++;
        } while (!check_id(student_id, database_ptr, number_of_students, ids_in_stack));
        ids_in_stack[i] = student_id;
        int index = id_index(student_id, database_ptr, number_of_students);
        Stack_t *node = malloc(sizeof(Stack_t));
        node->student = &database_ptr[index];
        node->next = *stack_top;
        *stack_top = node;
    }
    free(ids_in_stack);
}


bool check_id(int student_id, Student_t *database_ptr, int number_of_students, const int *ids_in_stack_ptr) {
    for (int i = 0; i < number_of_students; i++) {
        if (ids_in_stack_ptr[i] == student_id)
            return false;
    }
    if (id_index(student_id, database_ptr, number_of_students) == -1) {
        return false;
    }
    return true;
}

void pop_students(Stack_t **stack_top) {
    puts("Stack data:\n");
    while (*stack_top != NULL) {
        Student_t *student = (*stack_top)->student;
        printf("Student with id: %d\nName: %s\nStudent card number: %d\n"
               "Average grade: %.2f\nAttendance: %d\nLogin: %s\n\n",
               *student->student_id, student->student_name, *student->student_record_number,
               *student->student_rating, *student->student_attendance, student->student_login);
        Stack_t *temp = *stack_top;
        *stack_top = (*stack_top)->next;
        free(temp);
    }
}