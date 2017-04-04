#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char stick_man[10][20];


/* Design
     (._.)
     \ | /
      \|/
       |
       |
      / \
     /   \
*/

#define MAX_LENGTH 30
#define MAX_TRY 5
void print_word(char *word, int try)
{
    system("clear");
    printf("Incercari: %d\n", try);
    printf("Cuvant: %s\n", word);

    if(try == 4)
    {
        strcpy(stick_man[1], "       |");
        strcpy(stick_man[2], "       |");
        strcpy(stick_man[3], "       |");
        strcpy(stick_man[4], "       |");
    }
    if(try == 3)
    {
        strcpy(stick_man[1], "       |");
        strcpy(stick_man[2], "       |");
        strcpy(stick_man[3], "       |");
        strcpy(stick_man[4], "       |");
        strcpy(stick_man[5], "        \\");
        strcpy(stick_man[6], "         \\");
    }
    if(try == 2)
    {
        strcpy(stick_man[1], "       |");
        strcpy(stick_man[2], "       |");
        strcpy(stick_man[3], "       |");
        strcpy(stick_man[4], "       |");
        strcpy(stick_man[5], "      / \\");
        strcpy(stick_man[6], "     /   \\");
    }
    if(try == 1)
    {
        strcpy(stick_man[1], "     \\ |");
        strcpy(stick_man[2], "      \\|");
        strcpy(stick_man[3], "       |");
        strcpy(stick_man[4], "       |");
        strcpy(stick_man[5], "      / \\");
        strcpy(stick_man[6], "     /   \\");
    }

    int i;
    for(i = 0; i < 7; i++)
        printf("%s\n", stick_man[i]);
    return ;
}

int main()
{
    strcpy(stick_man[0], "     (._.)\0");
    system("clear");
    printf("Dati un cuvant:");
    char *word, *guess;
    word  = (char *) malloc(sizeof(char) * MAX_LENGTH);
    guess = (char *) malloc(sizeof(char) * MAX_LENGTH);
    scanf("%s", word);
    int word_length = strlen(word);
    word[word_length] = '\0';
    strcpy(guess, word);
    system("clear");
    int i;
    for(i = 1; i < word_length - 1; i++)
        guess[i] = '*';

    int game = 1;
    int try = MAX_TRY;

    print_word(guess, try);
    while(game)
    {
        printf("Dati litera:");
        char letter;
        scanf("%c", &letter);
        scanf("%c", &letter);

        int letter_guessed = 0;
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
            system("clear");
            printf("AI CASTIGAT!\nCuvantul a fost: %s", word);
            game = 0;
        }
        else
        if(try == 0)
        {
            strcpy(stick_man[1], "     \\ | /");
            strcpy(stick_man[2], "      \\|/");
            system("clear");
            printf("AI PIERDUT!\nCuvantul a fost: %s\n", word);
            int i;
            for(i = 0; i < 7; i++)
                printf("%s\n", stick_man[i]);
            game = 0;
        }
        else
        print_word(guess, try);
    }

    free(guess);
    free(word);
    return 0;
}
