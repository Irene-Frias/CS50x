#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Ask for the card number.
    long num = get_long("Number: ");
    long temp_num = num;
    int digit;
    int sum1 = 0;
    int sum2 = 0;
    int count = 0;
    int end_digit = 0;

    // Extract all the last digits.
    while (num > 0)
    {
        // Extract the last digit.
        digit = num % 10;
        num /= 10;
        sum1 += digit;
        count++;

        // Extract the next digit.
        if (num > 0)
        {
            digit = (num % 10) * 2;
            num /= 10;
            sum2 += (digit % 10) + (digit / 10);
            count++;
        }
    }

    // Remove the final digits from the original number, reducing it until only the first two digits
    // remain.
    while (temp_num > 100)
    {
        temp_num /= 10;
    }
    end_digit = temp_num;

    // Add the two sums and check if it ends in 0.
    if ((sum1 + sum2) % 10 == 0)
    {
        // Determination of credit card.

        // American Express (15 digits starts with 34 or 37)
        if ((count == 15) && (end_digit == 34 || end_digit == 37))
        {
            printf("AMEX\n");
        }

        // MasterCard (16 digits starts with 51, 52, 53, 54 or 55)
        else if ((count == 16) && (end_digit >= 51 && end_digit <= 55))
        {
            printf("MASTERCARD\n");
        }

        // Visa (13 or 16 digits starts with 4)
        else if ((count == 13 || count == 16) && (end_digit / 10 == 4))
        {
            printf("VISA\n");
        }
        // If it is none of the above, print "INVALID" with a break line "\n".
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
