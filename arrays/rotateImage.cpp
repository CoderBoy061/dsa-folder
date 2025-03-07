// Leetcode - 48 Rotate Image / Matrix 

// TC - O(n/2 * n\2) + O(n * n/2 + )


// class Solution {
//     public:
//         void rotate(vector<vector<int>>& matrix) {
//             /*
//               Approach -
//                 If we notice the answer mnatrix, the first row becomes the last
//               column means a[o][1] = arr[0][n-1]
    
//                 we are going to transpose the matrix
//                 arr[i][j] = arr[j][i];
    
//                 and then we will simpoly revese the row and that woll be our answer
    
//             */
    
//             // transpose the matrix
//             int n = matrix.size();
//             for (int i = 0; i < n - 1; i++) {
//                 for (int j = i + 1; j < n ; j++) {
//                     swap(matrix[i][j], matrix[j][i]);
//                 }
//             }
    
//             // now reverse the row only
    
//             for (int i = 0; i < n; i++) {
//                 reverse(matrix[i].begin(), matrix[i].end());
//             }
//         }
//     };