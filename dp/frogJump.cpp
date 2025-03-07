// GFG - Given an integer array height[] where height[i] represents the height of the i-th stair, a frog starts from the first stair and wants to reach the top. From any stair i, the frog has two options: it can either jump to the (i+1)th stair or the (i+2)th stair. The cost of a jump is the absolute difference in height between the two stairs. Determine the minimum total cost required for the frog to reach the top.

// Example:

// Input: heights[] = [20, 30, 40, 20] 
// Output: 20
// Explanation:  Minimum cost is incurred when the frog jumps from stair 0 to 1 then 1 to 3:
// jump from stair 0 to 1: cost = |30 - 20| = 10
// jump from stair 1 to 3: cost = |20-30|  = 10
// Total Cost = 10 + 10 = 20

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
       int tabSol(int idx, vector<int>& heights) {
           int n = heights.size();
           vector<int>dp(n+1, -1);
           dp[0] =0;
           for(int i=1;i<n;i++){
               int left = dp[i-1] + abs(heights[i] - heights[i-1]);
               int right =INT_MAX;
               
               if(i >1){
                   right = dp[i-2] + abs(heights[i] - heights[i-2]);
               }
             dp[i] = min(left,right);
           }
           return dp[n-1];
       }
    // int memoSol(int idx,vector<int>& heights, vector<int>&dp){
    //     if(idx == 0) return 0;
    //     if(dp[idx] != -1) return dp[idx];
    //     int left = memoSol(idx-1, heights,dp) + abs(heights[idx] - heights[idx-1]);
    //     int right =INT_MAX;
    //     if(idx >1) {
    //         right = memoSol(idx-2, heights,dp) + abs(heights[idx] - heights[idx-2]);
    //     }
    //     return dp[idx] = min(left,right);
    // }
    // int recursion(int idx,vector<int>& heights ) {
    //     if(idx == 0) return 0;
        
    //     int left = recursion(idx-1, heights) + abs(heights[idx] - heights[idx-1]);
    //     int right =INT_MAX;
    //     if(idx >1) {
    //         right = recursion(idx-2, heights) + abs(heights[idx] - heights[idx-2]);
    //     }
    //     return min(left,right);
    // }
    
    int minCost(vector<int>& height) {
        int  n = height.size();
        // vector<int>dp(n+1,-1);
        // return tabSol(n-1, height);
        int prev1=0;
        int prev2=0;
        for(int i=1;i<n;i++){
            int left = prev1 + abs(height[i] - height[i-1]);
            int right=INT_MAX;
            if(i >1){
                right = prev2 + abs(height[i] - height[i-2]);
            }
            
            int curr = min(left,right);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
        // using tan
        // return recursion(n-1,height);
        // return memoSol(n-1, height, dp);
    }
};
