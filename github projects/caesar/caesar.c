#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //Loop to go through entire string argument one at a time starting from 0.

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int k = atoi(argv[1]);

    //We have prompted use for plaintext to print out Ciphertext.

    string plaintext = get_string("Plaintext: ");
    printf("Ciphertext: ");

    //We keep following through w/ variable as long as it is less than plaintext.

    for (int j = 0; j < strlen(plaintext); j++)
    {
        if (isupper(plaintext[j]))

            // Bringing var back to original ASCII value for formula.

        {
            printf("%c", (plaintext[j] - 65 + k) % 26 + 65);
        }

        else if (islower(plaintext[j]))
        {
            printf("%c", (plaintext[j] - 97 + k) % 26 + 97);
        }

        else
        {
            printf("%c", plaintext[j]);
        }
    }
    printf("\n");
}