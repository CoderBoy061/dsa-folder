#include <iostream>
#include <vector>
using namespace std;

int f(int n, vector<int> &dp)
{

    // check for base case
    if (n <= 1)
        return n;
    // if not -1, means the value is already stored in the dp vector

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = f(n - 1, dp) + f(n - 2, dp);
}
int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);

    cout << f(n, dp) << endl;

    return 0;
}