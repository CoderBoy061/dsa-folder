
// TC-O(n)
// SC-O(1)
// class Solution {
//     public:
//         int climbStairs(int n) {
//             if (n == 0)
//                 return 0;
//             if (n == 1)
//                 return 1;
//             int prev2 = 1;
//             int prev = 1;
    
//             for (int i = 2; i <= n; i++) {
//                 int curr = prev + prev2;
//                 prev2 = prev;
//                 prev = curr;
//             }
//             return prev;
//         };
//     };
    