#include <stdio.h>
#include "mystrlen.h"

int main(void)
{
    char s[MAXLEN];
    int len;

    while (1)
    {
        printf("Enter a string: ");
        if (fgets(s, MAXLEN, stdin) == NULL)
        {
            printf("Goodbye!\n");
            break;
        }

        len = mystrlen(s);

        if (len == MAXLEN || (len == 1 && s[0] == '\n'))
        {
            printf("Goodbye!\n");
            break;
        }
        else
        {
            printf(" %d\n", len);
        }
    }
    return 0;
}

/*

if (len == MAXLEN) {
     printf(": %d\n", len);
     //printf(" Input too long \n");
 } else {
     printf(": %d\n", len);

     //printf("You entered: %s", s);

 }

 //printf("Length: %d\n", len);
 //printf(": %d\n", len);

 //the execute funtion
 if (len == 1 && s[0] == '\n') {
     printf("Goodbye!\n");
     return 0;
 }
 return 0;

*/

// gcc -Wall -Werror -std=c11 -o mystrlen mystrlen.c lencalc.c
// give cs9024 week2 mystrlen.c lencalc.c mystrlen