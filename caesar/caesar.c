#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char rotate(char c, int i);

int main(int argc, string argv[])
{

    if (argc == 2)
    {
        int key =  atoi(argv[1]);
        if (key >= 0)
        {
        if (isdigit(*argv[1]))
        {
            string text =  get_string("Enter Text: ");
            printf("ciphertext: ");
            for (int i = 0; i < strlen(text); i++)
            {
                char a = rotate(text[i],key);
                printf("%c",a);
            } printf("\n");
        }
        else if (isalnum(*argv[1]) || isalnum(*argv[2]))
        {
            printf("Usage : ./caesar key\n");
            return 1;
        }
        }
        else
        {
            printf("Usage : ./caesar key\n");
            return 1;
        }
    }
    else if (argv[1] == 0)
    {
            printf("Usage :./caesar key\n");
            return 1;
    }
    else
        {
            printf("Usage : ./caesar key\n");
            return 1;
        }




}


char rotate(char c, int i)
{
        int a;
        if (isalpha(c))
        {
            if (isupper(c))
            {
                a = (c + i) ;
                if (a > 'Z')
                {
                    a = (a - 26);
                }
            }
            else
            {
                a = (c + i);
                if (a > 'z')
                {
                    a = (a - 26);
                }
            }
        }
        else
        {
                a = c;
        }
        return a;
}
