#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **stick_man;
/* Design
     (._.)
     \ | /
      \|/
       |
       |
      / \
     /   \
*/

#define MAX_TRY 5

#define clear "clear" // For Linux
//#define clear "cls"// For Windows

void print_word(char *word, int try)
{
    system(clear);
    printf("Incercari: %d\n", try);
    printf("Cuvant: %s\n", word);

    if(try <= 4)
        printf("%s", stick_man[try]);
    else
        printf("%s", stick_man[5]);
    return ;
}

char** create_stick_man(char **stick_man)
{
    int i;
    stick_man = (char **) malloc(sizeof(char *) * 10);

    for(i = 0; i < 10; i++)
        stick_man[i] = (char*) malloc(sizeof(char) * 120);

    strcpy(stick_man[5], "     (._.)\n\n\n\n\n\n\n");
    strcpy(stick_man[4], "     (._.)\n       |\n       |\n       |\n       |\n\n\n\0");
    strcpy(stick_man[3], "     (._.)\n       |\n       |\n       |\n       |\n        \\\n         \\\n\0");
    strcpy(stick_man[2], "     (._.)\n       |\n       |\n       |\n       |\n      / \\\n     /   \\\n\0");
    strcpy(stick_man[1], "     (._.)\n     \\ |\n      \\|\n       |\n       |\n      / \\\n     /   \\\n\0");
    strcpy(stick_man[0], "     (._.)\n     \\ | /\n      \\|/\n       |\n       |\n      / \\\n     /   \\\n\0");

    return stick_man;
}

char* read_word(char *word, int *word_length)
{
    int i = 0;
    char letter;
    printf("Dati un cuvant:");
    scanf("%c", &letter);
    if(letter == '\n')
    {
        printf("Eroare cuvant!\n");
        exit(1);
    }

    word  = (char *) malloc(sizeof(char) * 1);
    while(letter != '\n')
    {
        word  = (char *) realloc(word, sizeof(char) * (i + 1));
        word[i++] = letter;
        scanf("%c", &letter);
    }
    word[i] = '\0';
    (*word_length) = i;
    return word;
}

int main()
{
    char *word, *guess;
    int word_length, i, game = 1, try = MAX_TRY;

    system(clear);
    stick_man = create_stick_man(stick_man);

 // Get text from input
    word = read_word(word, &word_length);
    guess = (char *) malloc(sizeof(char) * word_length);
    strcpy(guess, word);

    for(i = 1; i < word_length - 1; i++)
        if(guess[i] != ' ' && guess[i] != guess[0] &&
           guess[i] != guess[word_length - 1])
            guess[i] = '*';
    system(clear);

 // Game on
    print_word(guess, try);
    while(game)
    {
        int letter_guessed = 0;
        char letter;
        printf("Dati litera:");
        scanf("%c", &letter);

        while(letter == '\n')
        {
            print_word(guess, try);
            printf("Dati litera:");
            scanf("%c", &letter);
        }

        for(i = 1; i < word_length - 1; i++)
            if(word[i] == letter)
            {
                guess[i] = letter;
                letter_guessed = 1;
            }

        if(letter_guessed == 0)
            try--;

        if(strcmp(guess, word) == 0)
        {
            system(clear);
            printf("AI CASTIGAT!\nCuvantul a fost: %s\n", word);
            game = 0;
        }
        else
        if(try == 0)
        {
            system(clear);
            printf("AI PIERDUT!\nCuvantul a fost: %s\n", word);
            printf("%s", stick_man[0]);

            game = 0;
        }
        else
        print_word(guess, try);

        // Get enter key
        scanf("%c", &letter);
    }

 // Free memory
    free(guess);
    free(word);
    for(i = 0; i < 10; i++)
        free(stick_man[i]);
    free(stick_man);
    return 0;
}
