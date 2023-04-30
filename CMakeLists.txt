cmake_minimum_required(VERSION 3.24)
project(RK2 C)

set(CMAKE_C_STANDARD 11)

add_executable(RK2 main.c json_parser.c json_parser.h database.c database.h cJSON-master/cJSON.h cJSON-master/cJSON.c)
