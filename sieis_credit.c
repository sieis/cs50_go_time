#include <stdio.h>
#include <cs50.h>

int digits(long num);
bool validate(long num);
string card_type(long num);


int main(void)
{
    //prompt for card number
    long long num = get_long("Number: ");
    //validate card
    if (validate(num))
    {
        printf("%s", card_type(num));
    }
    else
    {
        printf("INVALID\n");
    }
}

// number of digits in card function
int digits(long num)
{
    int count = 0;
    while (num != 0)
    {
        num /= 10;
        count++;
    }
    return count;
}

//validate function
bool validate(long num)
{
    long odds = 0;
    long current = 0;
    long evens = 0;
    long total = 0;

    while (num > 0)
    {
        current = num / 10 % 10 * 2;
        odds = odds + (current % 10 + current / 10);
        evens = evens + (num / 1 % 10);
        num = num / 100;
    }
    total = evens + odds;
    printf("total: %lu\n", total);
    if (total % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// card_type function
string card_type(long num)
{
    if (((digits(num) == 13) && (num / 1000000000000 == 4)) || ((digits(num) == 16) && (num / 1000000000000000 == 4)))
    {
        string c_type = "VISA\n";
        return c_type;
    }
    else if ((digits(num) == 15) && (((num / 10000000000000) == 34) || (num / 10000000000000) == 37))
    {
        string c_type = "AMEX\n";
        return c_type;
    }
    else if ((digits(num) == 16) && ((num / 100000000000000 == 51)  || (num / 100000000000000 == 52) ||
                                     (num / 100000000000000 == 53) || (num / 100000000000000 == 54) || (num / 100000000000000 == 55)))
    {
        string c_type = "MASTERCARD\n";
        return c_type;
    }
    else
    {
        return "INVALID\n";
    }
}

