cmake_minimum_required(VERSION 3.24)
project(RK2 C)

set(CMAKE_C_STANDARD 11)

add_executable(RK2 main.c src/json_parser.c include/json_parser.h src/database.c include/database.h cJSON-master/cJSON.h cJSON-master/cJSON.c src/stack.c include/stack.h)
