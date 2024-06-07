This is a custom algorithm written by me in C using linked list to parse mathematical expressions

Space and quotes are internally processed and managed

Supported Numbers: +ve, -ve, decimal

Supported Operators: Multi-Bracket, Divide, Multiply, Plus, Minus

Basic error in case expression is incorrect

Tested on latest - FreeBSD and Debian

gcc -o evaluate evaluate.c


./evaluate "3 * ( 1 + 2 ) * 2 * ( 3.5 + 4.5 )"

./evaluate "3 * ( -1 + 2 ) * -2 * 4.8"

./evaluate "3 * ( 1 + 2 ) + 6 * ( 2 + 3 * ( 3 + 4 ) )"

./evaluate "( 1 + 2 ) ^ 2 + 6 * ( 2 + 3 * ( 3 ^ 2 + 4 ) )"

You can even use & | < > =
Currently >= and <= is supported but can be easily implemented 

Using greater sign between the two expressions

./evaluate "( 1 + 2 ) ^ 2 > ( 3 ^ 2 + 4 )"


Note space and quotes are ignored so doesn't matter
