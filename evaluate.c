#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef enum {bracket, operator, value} Object;

typedef struct Node {

    unsigned char level;

    union {

        double number;

        char operator;
    };

    Object type;

    struct Node *prev;

    struct Node *next;

} Node;


Node *Head, *Tail;

void createnode(Object obj, double number, char operator) {

    Node *temp;
    
    temp = (Node*)malloc(sizeof(Node));

    temp->type = obj;

    temp->next = NULL;
    temp->prev = NULL;

    if(obj == value) {

        temp->number = number;

    }
    else {

        temp->operator = operator;

    }
    
    if(Head == NULL) {

        Head = temp;

        Tail = temp;

        Head->next = Tail;

        Tail->prev = Head;

    }

    else {

        Head->prev = NULL;

        temp->prev = Tail;
        
        temp->next = NULL;

        Tail->next = temp;

        Tail = temp;

        Tail->next = NULL;

    }



}

void deletechain() {

    Node *temp;

    while(Head != NULL) {

        temp = Head;
    
        if(Head == Tail)
            
            Head = NULL;

        else
        {
            Head->prev = NULL;

            Head = Head->next;
        }

        free(temp);

    } 
}


void printchain() {

    Node *Pointer;
    
    Pointer = Head;

    while(Pointer != NULL)
    {

        if(Pointer->type == value)

            printf("%f",Pointer->number);

        else

            printf("%c",Pointer->operator);
   
        Pointer = Pointer->next;

    } 

    printf("\n");

}


void parse(Node **head, Node **tail, char ops) {

    Node *Pointer, *previous, *next;
    
    Pointer = *head;

    double result;


    while(*head != *tail && Pointer != NULL)
    {
        
        if(Pointer->type == operator && Pointer->operator == ops && Pointer->prev->type != bracket && Pointer->next->type != bracket)
        {

            if(ops == '*' && Pointer->operator == ops)

                result = Pointer->prev->number * Pointer->next->number;

            if(ops == '+' && Pointer->operator == ops)

                result = Pointer->prev->number + Pointer->next->number;

            Pointer->number = result;

            Pointer->type = value;

            previous = Pointer->prev;

            next = Pointer->next;

            if(previous->prev != NULL)
            {

                Pointer->prev = previous->prev;

                previous->prev->next = Pointer;

            }
            else {

                *head = Pointer;
                Pointer->prev = NULL;
            }

            if(next->next != NULL)
            {
                Pointer->next = next->next;

                next->next->prev = Pointer;
            }
            else {


                *tail = Pointer;
                Pointer->next = NULL;

            }

            free(previous);

            free(next);

        }

        else 
        {
            Pointer = Pointer->next;

        }

    } 

}

void parsebl(Node **head, Node **tail, char open, char close, char ops) {

    Node *Start, *Pointer, *previous, *next;
   
    Start = *head;

    Pointer = Start->next;

    while(*head != *tail && Pointer != NULL)
    {
        
        if(Pointer->operator == open) {

            Start = Pointer;

        }

        if(Start->operator == open && Pointer->operator == close)
        {

            parse(&Start->next, &Pointer->prev, ops);

            Start = Pointer;

        }

        Pointer = Pointer->next;
    }


}

int flushbracket(Node **head, Node **tail) {

    int resolutioncount = 0;

    Node *Pointer, *previous, *next;
    
    Pointer = *head;


    while(*head != *tail && Pointer != NULL)
    {
        if(Pointer->prev != NULL && Pointer->next != NULL) 
        {
            if(Pointer->prev->operator == '(' && Pointer->next->operator == ')') 
            {

                resolutioncount++;

                previous = Pointer->prev;

                next = Pointer->next;

                if(previous->prev != NULL)
                {

                    Pointer->prev = previous->prev;

                    previous->prev->next = Pointer;

                }
                else {

                    *head = Pointer;
                    Pointer->prev = NULL;
                }

                if(next->next != NULL)
                {
                    Pointer->next = next->next;

                    next->next->prev = Pointer;
                }
                else {


                    *tail = Pointer;
                    Pointer->next = NULL;

                }

                free(previous);

                free(next);

            }

        }

        Pointer = Pointer->next;

    } 

    return resolutioncount;

}

char* extract(const char* string) {

    int index = 0, in = 0;

    int length = strlen(string);

    char *input = (char*) malloc(sizeof(char) * length);

    while(string[index] != '\0') {

        if(string[index] != ' ' && string[index] != '"')
        {
            input[in] = string[index];

            in++;
        }

        index++;
    }


    while(*input) {

        if (isdigit(*input)) {
            
            double number = strtod(input, &input);

            createnode(value, number, '~');
        }

        else {

            char c = input[0];

            switch(c) {

                case '(': createnode(bracket, 0, '('); break;

                case ')': createnode(bracket, 0, ')'); break;

                case '*':  createnode(operator, 0, '*');break;

                case '+':  createnode(operator, 0, '+');break;

                default: break;

            }

            input++;

        }

    }

}


void processchain() {

    while(1)
    {
        /*printchain();*/

        parsebl(&Head, &Tail, '(', ')', '*');

        parsebl(&Head, &Tail, '(', ')', '+');

        if(!flushbracket(&Head, &Tail))

            break;

    
    }

    parse(&Head, &Tail, '*');

    parse(&Head, &Tail, '+');

    printchain();

    deletechain();
}


int main(int argc, char const *argv[]) {

    extract(&argv[1][0]);
    
    processchain();

    return 1;

}
