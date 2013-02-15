/**********************************************
*   Caesar Cipher
*
*   By Mike Brown
*   CS50 2012
*
**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

char CaesarMe(char letter, int key);

int main(int argc, string argv[])
{
    int key;
    if ( argc == 2 )
    {
        key = atoi(argv[1]);
        string plaintext;
        
        //printf("You have provided a key of %d.\n", key);
        
        if ( key < 1 )
        {
            printf("Provide 1 non-negative integer.\n");
            return 1;
        }
        
        do
        {
            //printf("Provide the text to be encrypted: ");
            plaintext = GetString();
        }
        while (strcmp(plaintext, "") == 0);
        
        //printf("The text you chose is: \"%s\"\n", plaintext);
        
        int text_len = strlen(plaintext);
        char cipher_chars[text_len];
        
        for (int i = 0; i < text_len; i++)
        {
            cipher_chars[i] = CaesarMe(plaintext[i], key);
        }
        
        //printf("Your ciphertext is: ");
        
        for (int i = 0; i < text_len; i++)
        {
            printf("%c", cipher_chars[i]);
        }
        printf("\n");
        
        return 0;
    }
    else
    {
        printf("Provide 1 non-negative integer.\n");
        return 1;
    }
}

/**
 * Shifts provided character the amount of letters
 * specified by the key.
 */
char CaesarMe(char letter, int key)
{
    int position;
    if (letter >= 'A' && letter <= 'Z')
    {
        position = letter - 'A';
        letter = (key + position) % 26 + 'A';
    }
    else if (letter >= 'a' && letter <= 'z')
    {
        position = letter - 'a';
        letter = (key + position) % 26 + 'a';
    }
    return letter;
}

