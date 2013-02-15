/***************************************
*   Mario Pyramid
*
*   By Mike Brown
*   CS50 2012
*
*   Creates a half pyramid like at the
*   end of the levels in Mario.
*
***************************************/
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // ask for height of pyramid
    int height;
    while (height < 0 || height > 23)
    {
        printf("Height: ");
        height = GetInt();
    }
    
    // print out half pyramid
    string block = "#";
    string space = " ";
    for (int i = 1; i <= height; i++)
    {
        for (int j = height - i; j > 0; j--)
        {
            printf("%s", space);
        }
        for (int k = 0; k <= i; k++)
        {
            printf("%s", block);
        }
        printf("\n");
    }
    return 0;
}
