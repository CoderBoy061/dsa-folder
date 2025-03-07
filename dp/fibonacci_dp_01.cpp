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
    vector<int> dp(n + 1, -1); // step 1 - always declare a vector

    cout << f(n, dp) << endl;

    // using tabulation to avoid extra spaces

    int prev2=0;
    int prev =1;

    for(int i=2;i<=n;i++){
        int curr = prev+prev2;
        prev2 = prev;
        prev = curr;
    }
    cout << prev <<endl;

    return 0;
}