// 4. Knapsack Problem: Solve the 0/1 knapsack problem.
// #include <bits/stdc++.h> 
// int recSol(int idx, int maxWeight,vector<int> wt,vector<int> val){
// 	if(idx ==0){
// 		if(wt[0] <= maxWeight){
// 			return val[0];
// 		}else{
// 			return 0;
// 		}
// 	}

// 	int notTake = 0 + recSol(idx-1, maxWeight, wt,val);

// 	int take  = INT_MIN;

// 	if(wt[idx] <= maxWeight){
// 		take = val[idx] + recSol(idx-1, maxWeight-wt[idx], wt, val);
// 	}
// 	return max(take, notTake);
// }
// int memoSolve(int idx, int maxWeight,vector<int> wt,vector<int> val, vector<vector<int>> &dp){
// 	if(idx ==0){
// 		if(wt[0] <= maxWeight){
// 			return val[0];
// 		}else{
// 			return 0;
// 		}
// 	}
// 	// if the part is already been computed then simply return that
// 	if(dp[idx][maxWeight] != -1) return dp[idx][maxWeight];

// 	int notTake = 0 + recSol(idx-1, maxWeight, wt,val);
// 	int take  = INT_MIN;

// 	if(wt[idx] <= maxWeight){
// 		take = val[idx] + recSol(idx-1, maxWeight-wt[idx], wt, val);
// 	}
// 	return dp[idx][maxWeight] = max(take, notTake);

// }
// int tabuSol(vector<int> wt, vector<int> val, int n, int maxWeight) {
// 	vector<vector<int>> dp(n , vector<int>(maxWeight+1, 0));
// 	  // Initializing the first row properly
//     for(int W = 0; W <= maxWeight; W++) {
//         if(wt[0] <= W) dp[0][W] = val[0];
//         else dp[0][W] = 0;
//     }

//     for(int idx = 1; idx < n; idx++) {
//         for(int W = 0; W <= maxWeight; W++) {
//             int notTake = dp[idx-1][W];
//             int take = INT_MIN;
//             if(wt[idx] <= W) {
//                 take = val[idx] + dp[idx-1][W - wt[idx]];
//             }
//             dp[idx][W] = max(take, notTake);
//         }
//     }
//     return dp[n-1][maxWeight];
// }
// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
// {
// 	// vector<vector<int>> dp(n , vector<int>(maxWeight+1, -1));
// 		return tabuSol(weight,value,n,maxWeight);
// 	// return memoSolve(n-1, maxWeight, weight, value,dp);
// 	// return recSol(n-1, maxWeight, weight, value);
// }