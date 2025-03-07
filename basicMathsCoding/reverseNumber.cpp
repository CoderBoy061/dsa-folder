#include <iostream>

using namespace std;

int reverseNumber(int n)
{
    while (n != 0)
    {
        int digit = n % 10;
        cout << digit << endl;
        n = n / 10;
    }
}

void isArmstrong(int n)
{
    int duplicate = n;
    int sum = 0;

    while (n != 0)
    {

        int dig = n % 10;

        sum += dig * dig * dig;
    }
    if (sum == n)
    {
        cout << true << endl;
    }
    cout << false << endl;
}
int main()
{
    int n = 153;
    // reverseNumber(n);
    isArmstrong(n);
    return 0;
}