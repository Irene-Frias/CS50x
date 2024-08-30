#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Show the value height and the user can change it.
    int number;
    do
    {
        number = get_int("Height: ");
    }

    // Height of block between 1 to 8.
    while (number < 1 || number > 8);

    // Block for each row of pyramid.
    for (int i = 0; i < number; i++)
    {
        // Space before the "#".
        for (int j = 0; j < number - i - 1; j++)
        {
            printf(" ");
        }

        // Left-hand side of the pyramid.
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        // Line break "\n" at the end of each row.
        printf("\n");
    }
}
