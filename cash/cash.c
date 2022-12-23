#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    int cents;
    //Ask For Number of Cents
    do
    {
        cents = get_int("Number Of Cents: ");
    }
    while (cents < 0);
    return cents;

}

int calculate_quarters(int cents)
{
    //Calculate Number Of Quarters
    int q = 0, Q = 0;
    while (cents - q >= 25)
    {
        q = q + 25;
        Q = q / 25;
    }
    return Q;
}

int calculate_dimes(int cents)
{
    //Calculate Number Of Dimes
    int d = 0, D = 0;
    while (cents - d >= 10)
    {
        d = d + 10;
        D = d / 10;
    }
    return D;
}

int calculate_nickels(int cents)
{
    //Calculate Number Of Nickels
    int n = 0, N = 0;
    while (cents - n >= 5)
    {
        n = n + 5;
        N = n / 5;
    }
    return N;
}

int calculate_pennies(int cents)
{
    //Calculate Number Of Pennies
    int p = 0, P = 0;
    while (cents - p >= 1)
    {
        p = p + 1;
    }
    return p;
}
