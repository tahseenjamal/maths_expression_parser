This is a custom algorithm written by me in C using linked list to parse mathematical expressions

Space and quotes are internally processed and managed

Supported Numbers: +ve, -ve, decimal

Supported Operators: Multi-Bracket, Divide, Multiply, Plus, Minus

No error check for incorrectly done brackets or operators

Tested on latest - FreeBSD and Debian

gcc -o evaluate evaluate.c


./evaluate "3 * ( 1 + 2 ) * 2 * ( 3.5 + 4.5 )"

./evaluate "3 * ( -1 + 2 ) * -2 * 4.8"


