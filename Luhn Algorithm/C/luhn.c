#include <stdio.h>
#include <cs50.h>
#include <math.h>

// Function declaration
long get_digit(long number, int position);
bool validation(long number, int digits);
string get_type(long card_number, int digits);

int main(void)
{
    // Variable declaration and inizialitation
    long card_number;
    long temp_number;
    int digits = 0;

    card_number = get_long("Number: ");

    temp_number = card_number;

    // Counting the number of digits for credit card number
    while (temp_number > 0)
    {
        temp_number = temp_number / 10;
        digits++;
    }

    // Validating credit card
    bool valid = validation(card_number, digits);
    if (valid)
    {
        // Display credit card type if it passes validation check
        string card = get_type(card_number, digits);
        printf("%s", card);
    }
    else
    {
        // Display invalid if it doesn't pass validation check
        printf("INVALID\n");
    }

}

// Function to get the number on given position
long get_digit(long number, int position)
{
    long num;

    num = number / pow(10, position - 1);
    num = num % 10;

    return num;
}

// Function to validate whether it is a credit card or not
bool validation(long card_number, int digits)
{
    long temp = 0;
    long num;
    int temp_digits = 0;

    // Checking whether number of digits is correct
    if (digits < 13 || digits == 14 || digits > 16)
    {
        return false;
    }

    // Performing Luhn's Algorithm to validate credit card
    else
    {
        for (int i = 2; i <= digits; i = i + 2)
        {
            num = get_digit(card_number, i) * 2;
            int temp_num = num;
            while (temp_num > 0)
            {
                temp_num = temp_num / 10;
                temp_digits++;
            }
            for (int j = 1; j <= temp_digits; j++)
            {
                temp_num = get_digit(num, j);
                temp = temp + temp_num;
            }

        }

        for (int i = 1; i <= digits; i = i + 2)
        {
            num = get_digit(card_number, i);
            temp = temp + num;
        }

        if (temp % 10 == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

}

// Function to get the type of credit card (AMEX, VISA or MASTERCARD)
string get_type(long card_number, int digits)
{
    long digit1, digit2;

    digit1 = get_digit(card_number, digits);

    if (digit1 == 4)
    {
        // Return VISA if the credit card starts with 4
        return "VISA\n";
    }
    else
    {
        digit2 = get_digit(card_number, digits - 1);
        if (digit1 == 3 && (digit2 == 4 || digit2 == 7))
        {
            // Return AMEX if the credit card starts with 34 or 37
            return "AMEX\n";
        }
        else if (digit1 == 5 && (digit2 == 1 || digit2 == 2 || digit2 == 3 || digit2 == 4 || digit2 == 5))
        {
            // Return MASTERCARD if the credit card starts with 51, 52, 53, 54 or 55
            return "MASTERCARD\n";
        }
        else
        {
            // Return INVALID if it doesn't fall into any type above
            return "INVALID\n";
        }
    }

}
