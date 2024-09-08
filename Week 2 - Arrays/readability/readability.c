#include <cs50.h>
#include <stdio.h>
#include <string.h> /* Order a character string and obtains the length of a word. */
#include <ctype.h> /* Identify uppercase from lowercase. */
#include <math.h> /* Basic mathematical operations.*/

int main(void)
{
    // Prompt the user for some text.
    string text = get_string("Text: ");

   // Declare letters, words and sentences variables.
    int letters = 0, words = 1, sentences = 0;

    // Step through text character by character.
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Check if the character is a letter.
        if (isalpha(text[i]))
        {
            letters++;
        }
        // Check if character is a space for word count.
        else if (text[i] == ' ')
        {
            words++;
        }
        // Check if character is a point, exclamation or question mark.
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    // Calculate the average number of letters per 100 words.
    float L = (float) letters / words * 100;
    // Calculate the average number of sentences per 100 words.
    float S = (float) sentences / words * 100;

    // Apply the Coleman-Liau formula to calculate the readability index.
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Round the index to the nearest integer and print the result based on the value.
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        // Print the index rounded to the nearest degree.
        printf("Grade %i\n", (int) round(index));
    }
}
