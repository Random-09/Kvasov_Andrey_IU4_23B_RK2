#include <stdio.h>
#include "json_parser.h"
#include "database.h"

int main() {
    Student_t *database;
    database = (Student_t *) malloc(DB_CAPACITY * (sizeof(Student_t)));
    int number_of_students = 0;
    json_parser("../database.json", database, &number_of_students);
}
