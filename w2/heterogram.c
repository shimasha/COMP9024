#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// heterogram function

bool isHeterogram(char input[])
{
    // step 1 - create an array to count the letter repeat count

    int CounterL[26] = {0};

    // step 2 - iterate through the characters of the input phrase

    for (int i = 0; input[i] != '\0'; i++)
    {
        // step 3 - checking the case sensitivity

        if ((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z'))
        {
            // step 4 - convert the letters to lovercase
            char convertL;

            if (input[i] >= 'A' && input[i] <= 'Z')
            {

                // EX =('a' - 'A') is equivalent to 97 - 65, which equals 32.
                convertL = input[i] + ('a' - 'A');
            }
            else
            {
                convertL = input[i];
            }

            // step 4 - incrementing the count of a particular letter in convertL
            CounterL[convertL - 'a']++;
        }
    }

    // step 5 - check for recurring letters
    for (int i = 0; i < 26; i++)
    {
        // if the count is greater than one then its repeated its FALSE
        if (CounterL[i] > 1)
        {
            return false;
        }
    }
    // or return a TRUE which is a heterogram
    return true;
}

// main method
int main()
{
    char getinput[64];

    // tell the user to enter a word or a phrase

    printf("Enter a word or phrase: ");
    scanf("%[^\n]%*c", getinput);

    // Check if the entered phrase is a heterogram and display the result

    if (isHeterogram(getinput))
    {
        printf("\"%s\" is a heterogram\n", getinput);
    }
    else
    {
        printf("\"%s\" is not a heterogram\n", getinput);
    }

    return 0;
}

/*
<----------- psuedo code ------------>

Function isHeterogram(phrase)
    Initialize letterCount array of size 26 with all elements
    start set to 0

    For each character (char) in phrase
        If char is a letter (A-Z or a-z)
            Convert char to lowercase
            Increment letterCount[char - 'a']

    For each count in letterCount
        If count > 1
            Return false  // Not a heterogram

    Return true  // Heterogram

End Function isheterogram

Function main()
    Declare Input array of size 64 to get user input

    Output "Enter a word or phrase: "
    Input user -Input

    If isHeterogram(user -Input)
        Output "The entered phrase is a heterogram."
    Else
        Output "The entered phrase is not a heterogram."

End Function main

<---------------------------->

*/

// gcc -Wall -Werror -std=c11 -o heterogram heterogram.c
// 9024 dryrun heterogram //give cs9024 week3 heterogram.c