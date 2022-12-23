#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        //Specifying the range of values
        n = get_int("Height (1-8): ");

    }
    while (n < 1 || n > 8);
    //For changing rows
    for (int i = 1 ; i <= n ; i++)
    {
        //For right-indentation
        for (int j = 0 ; j < n - i ; j++)

        {
            printf(" ");
        }
        //For printing i number of #
        for (int a = 0 ; a < i ; a++)

        {

            printf("#");

        }


        printf("\n");

    }

}