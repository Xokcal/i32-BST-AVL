cmake_minimum_required(VERSION 3.27)
project(i32_BST C)

set(CMAKE_C_STANDARD 11)

add_executable(i32_BST bst/main.c
        bst/typedef.h
        bst/bst.c
        bst/bst.h)
