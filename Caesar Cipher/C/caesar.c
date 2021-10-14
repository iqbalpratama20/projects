#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Checking command line argument input
    if (argc == 2)
    {
        // check whether the key contains non-numeric value
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (!isdigit(argv[1][i]))
            {
                // If key contains non-numeric value, exit with 1
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        // Convert key from string to integer
        int key = atoi(argv[1]) % 26;
        // Get plaintext
        string plain = get_string("plaintext: ");
        printf("ciphertext: ");
        for (int i = 0; i < strlen(plain); i++)
        {
            if ((plain[i] >= 'a' && plain[i] <= 'z') || (plain[i] >= 'A' && plain[i] <= 'Z'))
            {
                if (plain[i] >= 'a' && plain[i] <= 'z')
                {
                    // Caesar's algorithm with lowercase character
                    int ci = ((plain[i] - 'a' + key) % 26) + 'a';
                    printf("%c", ci);
                }
                else
                {
                    // Caesar's algorithm with uppercase character
                    int ci = ((plain[i] - 'A' + key) % 26) + 'A';
                    printf("%c", ci);
                }
            }
            else
            {
                // Print symbol (eg. ! , . ?)
                printf("%c", plain[i]);
            }
        }
        printf("\n");
        return 0;

    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}