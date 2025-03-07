// 746. Min Cost Climbing Stairs
// Easy
// Topics
// Companies
// Hint
// You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

// You can either start from the step with index 0, or the step with index 1.

// Return the minimum cost to reach the top of the floor.

#include <iostream>
#include <vector>
using namespace std;
// using plain recurison
int solve1(vector<int> &cost, int n)
{
    if (n <= 1)
    {
        return cost[n];
    }

    int ans = cost[n] + min((cost, n - 1), solve1(cost, n - 2));
    return ans;
}
// TC-O(n)
// Sc -O(n)
int solve2(vector<int> &cost, int n)
{
    vector<int> dp;
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2; i < n; i++)
    {
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 1]);
    }
    return min(dp[n - 1], dp[n - 2]);
}
// TC - O(n)
// SC -O(1)
int solv3(vector<int> &cost, int n){
    int prev = cost[0];
    int prev1 = cost[1];

    for(int i=2;i<n;i++){
        int curr =  cost[i]+ min(prev,prev1);

        prev1 = prev;
        prev = curr;
    }
    return min(prev1, prev);

}

int main()
{
    vector<int> cost = {10, 15, 20};
    int n = cost.size();
    vector<int> dp(n + 1, -1); // initially the valued will be -1
    cout << solve2(cost, n);
    return 0;
}