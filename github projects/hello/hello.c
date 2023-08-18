#include <stdio.h>
#include <cs50.h>check50 cs50/problems/2022/x/hello

int main(void)
{
    // User provides name
    string name = get_string("What's your name? ");
    printf("hello, %s\n", name);
}