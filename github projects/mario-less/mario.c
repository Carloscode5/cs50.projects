#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Declaring variables for equation
    int height, row, column, space;
    //Created loop for staying w/in the parameters of 1 & 8
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    //Print hash on new line based on parameters
    for (row = 0; row < height; row++)
    {
        for (space = 0; space < height - row - 1; space++)
        {
            printf(" ");
        }
        for (column = 0; column <= row; column++)
        {
            printf("#");
        }
        printf("\n");
    }
}