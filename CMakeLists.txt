cmake_minimum_required(VERSION 3.20)
project(Practice C)

set(CMAKE_C_STANDARD 11)


add_executable(Practice
        "tp exam1/main.c" library/fonctions_PPile.c library/fonctions.h "library/fonctions_TPile.c")

