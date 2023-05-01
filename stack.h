#ifndef RK2_STACK_H
#define RK2_STACK_H

#include <stdbool.h>
#include "database.h"

typedef struct Stack {
     Student_t *student;
    struct Stack *next;
} Stack_t;


void push_students(Stack_t *stack_top, Student_t *database_ptr, int number_of_students);

bool check_id(int student_id, Student_t *database_ptr, int number_of_students, const int *ids_in_stack_ptr);

void pop_students(Stack_t *stack_head);


#endif
