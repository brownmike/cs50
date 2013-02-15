/***************************************
*   Greedy
*
*   By Mike Brown
*   CS50 2012
*
*   Calculates minimum number of coins
*   needed to add up to the change value
*   provided.
*
***************************************/
#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    // ask for change owed
    float change = 0.00;
    while (change < 1)
    {
        printf("Change to be returned: ");
        change = GetFloat();
        if (floor(change * 100) < 1) // provided value must be >= .01
            change = 0;
        else
            change = round(change * 100); // convert dollars to cents
    }
    
    // calculate minimum coins to create change
    int coins = 0, cents = change;
    coins = cents / 25;
    cents = cents % 25;
    coins = coins + cents / 10;
    cents = cents % 10;
    coins = coins + cents / 5;
    cents = cents % 5;
    coins = coins + cents / 1;
    
    // display result
    printf("%d\n", coins);
    
    return 0;
}
