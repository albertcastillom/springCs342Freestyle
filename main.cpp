#include <iostream>
#include <cmath>

using namespace std;

bool is_power_of_two(int num);
bool is_power_of_two_noLoop(int num);
bool is_prime(int num, int numSqrt);

void testFraction();

struct Fraction
{
    int numerator;
    int denominator;
};

void printFraction(const Fraction & fraction)
{
    if (fraction.numerator == 0)
    {
        cout << "0";
    }else if ( fraction.denominator == 0 )
    {
        cout << "cannot divide by zero";
    }else
    {
        cout << fraction.numerator << "/" << fraction.denominator << endl;
    }
}

int getGCD(int a, int b)
{
    int remainder = a % b;
    if (remainder == 0)
    {
        return b;
    }
    else
    {
        return getGCD(b, remainder);
    }
}

int main()
{

    const int num = 5; //num for finding power of 2 and if its a prime
    int numSqrt = round(sqrt(num)); // sqrt of num to find if its a prime
    bool primeResult = is_prime(num, numSqrt);
    bool result = is_power_of_two(num);
    bool second_result = is_power_of_two_noLoop(num);
    cout << boolalpha << result << endl;
    cout << boolalpha <<"no loop result: "<< second_result << endl;
    (primeResult) ? cout << "pass\n" : cout << "fail\n";

    testFraction();
    return 0;
}
void testFraction()
{

    Fraction fraction;
    fraction.numerator = 10;
    fraction.denominator = 2;
    Fraction fractionExcpected;
    fractionExcpected.numerator= 5;
    fractionExcpected.denominator = 1;

    if (fraction.numerator == 0 )
    {
        printFraction(fraction);
    }else if (fraction.denominator == 0)
    {
        cout << "cannot divide by zero";
    }else
    {
        int gcd = getGCD(fraction.denominator, fraction.numerator);
        Fraction fractionReduced;
        fractionReduced.numerator = fraction.numerator/gcd;
        fractionReduced.denominator = fraction.denominator/gcd;
        //printFraction(fraction);
        //printFraction(fractionReduced);
        if (fractionExcpected.numerator == fractionReduced.numerator && fractionExcpected.denominator == fractionReduced.denominator)
        {
            cout << "pass\n";
        }
        else
        {
            cout << "fail\n";
        }
    }

}
bool is_power_of_two(int num)
{
    if (num == 0 )
    {
        return false;
    }
    while (num != 1)
    {
        if (num % 2 ==0)
        {
            num = num/2;
        }
        else if (num % 2 !=0)
        {
            return false;
        }
    }
    return true;
}
bool is_power_of_two_noLoop(int num)
{
    if (num == 0 )
    {
        return false;
    }
    if ( (num & (num - 1)) == 0) //essentially if a number in its bit format only has one "1" and the rest are "0"s
        //its a power of two. if you subtract one from the number and use the And operator it will return all 0s if its a power of two
        //the And symbol compares each bit and returns 0 if they are different
    // 8 - 1 = 7 -> binary -> 111
    // 8 -> binary -> 1000
    // and symbol compares 0 and 1, then 1 and 0 three times. which return 0 overall.
    {
        return true;
    }
    return false;
}

bool is_prime (int num, int numSqrt)
{
    if (num == 0 || num == 1)
    {
        return false;
    }
    for (int i = 2; i<numSqrt; i++)
    {
        if (num % i == 0 )
        {
            return false;
        }
    }
    return true;
}