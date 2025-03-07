#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int countPrimes(int n)
{
    int count = 0;                     // to return the count
    vector<bool> isPrime(n + 1, true); //  initially all the number will be true, means every number is prime number
    // before that, let's handle the edge case
    if (n == 0 || n == 1)
    {
        return count;
    }
    // start loop from 2
    for (int i = 2; i < n; i++)
    {
        // if the number is present, then simply increement
        if (isPrime[i] == true)
        {
            count++;
        }
        // now discard the number which are multiply of the current number

        for (int j = i * 2; j < n; j = j + i)
        {
            isPrime[j] = false;
        }
    }
    return count;
}
int main()
{

    // check if the number is prime or not?
    // if the number is not divisible from 2 to  root of n means its a prime number
    // like 16 - can divide from 2 to 4, so its not a prime number
    int n = 16;

    cout << countPrimes(n) << endl;

    return 0;
}