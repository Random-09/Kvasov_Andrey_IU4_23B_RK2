#include "stack.h"

void push_students(Stack_t *stack_top, Student_t *database_ptr, int number_of_students) {
    puts("Enter students' IDs'");
    int ids_in_stack[number_of_students];
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
        node->next = stack_top;
        stack_top = node;
    }
}

bool check_id(int student_id, Student_t *database_ptr, int number_of_students, const int *ids_in_stack_ptr) {
    if (id_index(student_id, database_ptr, number_of_students) == -1)
        return false;
    for (int i = 0; i < number_of_students; i++) {
        if (ids_in_stack_ptr[i] == student_id)
            return false;
    }
    return true;
}

void pop_students(Stack_t *stack_top) {
    Stack_t *temp = stack_top;

}