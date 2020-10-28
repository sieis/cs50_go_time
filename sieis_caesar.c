#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    //get key from command line argument
    //validate ...only single argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //only digit characters
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        //convert argument to integer
    }
    int key;
    key = atoi(argv[1]);
    printf("key value is %i\n", key);


    //get plaintext w get_string
    string plaintext = get_string("plaintext: ");
    char cipher[strlen(plaintext)];
    int index;
    int shift;
    int back;


    //encipher
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (!isalpha(plaintext[i]))
        {
            //put in cipher text as is
            cipher[i] = plaintext[i];

        }
        else if (isupper(plaintext[i]))
        {
            //convert ascii to alphabetical index
            index = plaintext[i] - 65;
            //shift for upper(starts at 65)
            shift = (index + key) % 26;
            //convert back to ascii
            back = (shift + 65);
            //add to cipher array
            cipher[i] = (char)back;
        }
        else
        {
            //convert ascii to alphabetical index
            index = plaintext[i] - 97;
            //shift for lower(starts at 97)
            shift = (index + key) % 26;
            //convert back to ascii
            back = (shift + 97);
            //add to cipher array
            cipher[i] = (char)back;
        }
    }
    //print cipher text
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        printf("%c", cipher[i]);
    }
    printf("\n");
}
