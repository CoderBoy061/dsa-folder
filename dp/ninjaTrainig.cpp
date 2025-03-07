//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int solve(int day, int last, vector<vector<int>> &arr)
    {
        if (day == 0)
        {
            int maxi = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    maxi = max(maxi, arr[0][task]);
                }
            }
            return maxi;
        }
        int maxi = 0;
        for (int task = 0; task < 3; task++)
        {
            if (task != last)
            {
                int points = arr[day][task] + solve(day - 1, task, arr);
                maxi = max(maxi, points);
            }
        }
        return maxi;
    }
    //     Complexity Analysis

    // Time Complexity: O(N*4*3)

    // Reason: There are three nested loops

    // Space Complexity: O(N*4)
    int memoSolve(int day, int last, vector<vector<int>> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        if (day == 0)
        {
            int maxi = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    maxi = max(maxi, arr[0][task]);
                }
            }
            return maxi;
        }
        if (dp[day][last] != -1)
            return dp[day][last];
        int maxi = 0;
        for (int task = 0; task < 3; task++)
        {
            if (task != last)
            {
                int points = arr[day][task] + memoSolve(day - 1, task, arr);
                maxi = max(maxi, points);
            }
        }
        return dp[day][last] = maxi;
    }
    int maximumPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        // return solve(n-1, 3, arr);
        // return memoSolve(n-1,3,arr);
        vector<vector<int>> dp(n, vector<int>(4, -1));
        dp[0][0] = max(points[0][1], points[0][2]);
        dp[0][1] = max(points[0][0], points[0][2]);
        dp[0][2] = max(points[0][0], points[0][1]);
        dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

        // Iterate through the days starting from day 1
        for (int day = 1; day < n; day++)
        {
            for (int last = 0; last < 4; last++)
            {
                dp[day][last] = 0;
                // Iterate through the tasks for the current day
                for (int task = 0; task <= 2; task++)
                {
                    if (task != last)
                    {
                        // Calculate the points for the current activity and add it to the
                        // maximum points obtained on the previous day (recursively calculated)
                        int activity = points[day][task] + dp[day - 1][task];
                        // Update the maximum points for the current day and last activity
                        dp[day][last] = max(dp[day][last], activity);
                    }
                }
            }
        }

        // The maximum points for the last day with any activity can be found in dp[n-1][3]
        return dp[n - 1][3];
    }
};

// Time Complexity: O(N*4*3)
// Reason: There are three nested loops
// Space Complexity: O(4)
// Function to find the maximum points for ninja training
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Initialize a vector to store the maximum points for the previous day's activities
    vector<int> prev(4, 0);

    // Initialize the DP table for the first day (day 0)
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    // Iterate through the days starting from day 1
    for (int day = 1; day < n; day++)
    {
        // Create a temporary vector to store the maximum points for the current day's activities
        vector<int> temp(4, 0);
        for (int last = 0; last < 4; last++)
        {
            temp[last] = 0;
            // Iterate through the tasks for the current day
            for (int task = 0; task <= 2; task++)
            {
                if (task != last)
                {
                    // Calculate the points for the current activity and add it to the
                    // maximum points obtained on the previous day (stored in prev)
                    temp[last] = max(temp[last], points[day][task] + prev[task]);
                }
            }
        }
        // Update prev with the maximum points for the current day
        prev = temp;
    }

    // The maximum points for the last day with any activity can be found in prev[3]
    return prev[3];
}

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends