#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool is_valid_key(string s);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (!is_valid_key(argv[1]))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    string plaintext = get_string("plaintext:  "); // Hello!
    printf("ciphertext: ");
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        if (isalpha(plaintext[i]))
        {
            int index = toupper(plaintext[i]) - 'A';
            if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
                printf("%c", toupper(argv[1][index]));
            else
                printf("%c", tolower(argv[1][index]));
        }
        else
            printf("%c", plaintext[i]);
    }
    printf("\n");
}

bool is_valid_key(string s)
{
    int len = strlen(s);
    if (len != 26)
        return false;

    int freq[26] = {0};
    for (int i = 0; i < len; i++)
    {
        if (!isalpha(s[i]))
            return false;

        int index = toupper(s[i]) - 'A';
        if (freq[index] == 1)
            return false;
        freq[index]++;
    }
    return true;
}
