#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_WORDS 1000
#define MAX_LEN 1000
void toLowerStr(char *str)
{
    for (int i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
}
void removePunctuation(char *word)
{
    int i, j = 0;
    char clean[MAX_LEN];
    for (i = 0; word[i]; i++)
    {
        if (isalnum(word[i]))
        {
            clean[j++] = word[i];
        }
    }
    clean[j] = '\0';
    strcpy(word, clean);
}
int main()
{
    char paragraph[MAX_LEN];
    char words[MAX_WORDS][MAX_LEN];
    int freq[MAX_WORDS] = {0};
    int wordCount = 0;
    printf("Enter a paragraph:\n");
    fgets(paragraph, MAX_LEN, stdin);
    toLowerStr(paragraph);
    char *token = strtok(paragraph, " \n\t");
    while (token != NULL) {
        removePunctuation(token);
        int found = 0;
        for (int i = 0; i < wordCount; i++)
        {
            if (strcmp(words[i], token)== 0)
            {
                freq[i]++;
                found = 1;
                break;
            }
        }
        if (!found)
        {
            strcpy(words[wordCount], token);
            freq[wordCount] = 1;
            wordCount++;
        }

        token = strtok(NULL, " \n\t");
    }
    printf("\nWord Frequencies:\n");
    for (int i = 0; i < wordCount; i++)
    {
        printf("%s: %d\n", words[i], freq[i]);
    }
    return 0;
}
