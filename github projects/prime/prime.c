#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{

    //Checking if min number is greater than 0
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    //Checking if max number is greater than min number
    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}
//Calculating if min and max are prime and laying them out in chronological order
bool prime(int number)
{
    // TODO

    if (number <= 1)
    {
        return false;
    }
    if (number == 2 || number == 3)
    {
        return true;
    }
    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}
