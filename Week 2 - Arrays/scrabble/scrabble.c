#include <cs50.h>
#include <stdio.h>
#include <string.h> /* Order a character string and obtains the length of a word. */
#include <ctype.h> /* Identify uppercase from lowercase. */

// Points assigned to each letter of the alphabet.
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int score_mark(string word);

int main(void)
{
    // Prompt the user for two words.
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Compute the score of each word.
    int score1 = score_mark(word1);
    int score2 = score_mark(word2);

    // Print the winner.
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// Compute score for each player.
int score_mark(string word)
{
    int score = 0;
    
    // Go through the entire word to know the value to calculate.
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        // Checks if the character is uppercase (isupper) or lowercase (islower).
        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
        }
    }

    return score;
}
