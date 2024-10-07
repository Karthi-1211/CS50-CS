#include "dictionary.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

const unsigned int N = 26;

unsigned int hash_value;
unsigned int word_count;

node *table[N];

bool check(const char *word)
{
    hash_value = hash(word);

    node *cursor = table[hash_value];

    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

unsigned int hash(const char *word)
{
    unsigned int total = 0;
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        total += tolower(word[i]);
    }
    return total % N;
}
bool load(const char *dictionary)
{
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        printf("Unable open to %s\n", dictionary);
        return false;
    }

    char word[LENGTH + 1];

    while (fscanf(source, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Memory Error!\n");
            return false;
        }
        strcpy(n->word, word);
        hash_value = hash(n->word);
        n->next = table[hash_value];
        table[hash_value] = n;
        word_count++;
    }
    fclose(source);
    return true;
}
unsigned int size(void)
{
    if (word_count > 0)
    {
        return word_count;
    }
    return 0;
}
bool unload(void)
{

    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}
