This is a custom algorithm written by me in C using linked list to parse mathematical expressions

Space and quotes are internally processed and managed

Decimal numbers are supported

Operators allowed are round brackets, multiply and plus

Logic is simple that one can experiment and add >, <, power, divide, minus 

Currently haven't added unbalanced bracket check. It is a simple algo in case you want to add


Program compiled on Debian 9 using gcc. Below is the way to compile and use the program


gcc -o evaluate evaluate.c


./evaluate "3 * ( 1 + 2 ) * 2 * ( 3.5 + 4.5 )"


