cmake_minimum_required(VERSION 3.17)
project(ft_printf C)

set(CMAKE_C_STANDARD 99)

add_executable( ft_printf.h ft_printing.c ft_printf.c ft_pars_modifiers.c ft_printf.c init_flags.c print_str.c parsers.c print_char.c main.c)