/**********************************************
*   Vigenere Cipher
*
*   By Mike Brown
*   CS50 2013
*
**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

char VigenereMe(char letter, char key);

int main(int argc, string argv[])
{
    string key;
    if ( argc == 2 )
    {
        key = argv[1];
        string plaintext;
        int key_len = strlen(key);
        
        //printf("You have provided a key of %s.\n", key);
        
        // make sure key is only alpha chars
        for (int i = 0; i < key_len; i++)
        {
            if ( key[i] < 'A' || (key[i] > 'Z' && key[i] < 'a') || key[i] > 'z' )
            {
                printf("Provide a word composed only of alphabetical characters to use as a key.\n");
                return 1;
            }
            
            i++;
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
        
        int i = 0, j = 0;
        while (i < text_len)
        {
            if ( (plaintext[i] >= 'A' && plaintext[i] <= 'Z') || (plaintext[i] >= 'a' && plaintext[i] <= 'z') )
            {
                cipher_chars[i] = VigenereMe(plaintext[i], key[j]);
                i++;
                j = (j + 1) % key_len;
            }
            else
            {
                cipher_chars[i] = plaintext[i];
                i++;
            }
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
        printf("Provide a word composed only of alphabetical characters to use as a key.\n");
        return 1;
    }
}

/**
 * Shifts provided character the amount of letters
 * specified by the key.
 */
char VigenereMe(char character, char key)
{
    int character_position, key_position;
    if (character >= 'A' && character <= 'Z')
    {
        character_position = character - 'A';
        
        if ( key >= 'A' && key <= 'Z' )
            key_position = key - 'A';
        else if ( key >= 'a' && key <= 'z' )
            key_position = key - 'a';
        
        character = (key_position + character_position) % 26 + 'A';
    }
    else if (character >= 'a' && character <= 'z')
    {
        character_position = character - 'a';
        
        if ( key >= 'A' && key <= 'Z' )
            key_position = key - 'A';
        else if ( key >= 'a' && key <= 'z' )
            key_position = key - 'a';
        
        character = (key_position + character_position) % 26 + 'a';
    }
    return character;
}

