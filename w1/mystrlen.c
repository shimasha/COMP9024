#include "mystrlen.h"

int mystrlen(char *s)
{
    int len1;

    // check the length and iterate

    for (len1 = 0; *s; len1++, s++)
    {
        if (len1 >= MAXLEN)
        {
            return MAXLEN;
        }
    }
    return len1;
}