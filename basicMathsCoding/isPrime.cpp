#include <iostream>
#include<string.h>
using namespace std;

string isPrime(int n)
{
    if (n <= 1) return "Non Prime";
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return "Non Prime";
        }
    }
    return "Prime";
}
int main()
{

    // check if the number is prime or not?
    // if the number is not divisible from 2 to  root of n means its a prime number
    // like 16 - can divide from 2 to 4, so its not a prime number
    int n = 16;

    cout << isPrime(n) << endl;

    return 0;
}