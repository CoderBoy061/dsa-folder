
/*
    Approach :-
    1. we can initialize reperat and missing element with -1, if the grid does not contain any negetive lements
    2. we can take a sum varibale to store the sum of all the present elements
    3. We can take an unordered_map to store the frequency of the elements
    4. Now traverse the grid and store the frequency and the total sum
    5. after that we can run a loop till the sum to generate 1 to n elements - n is eqaul to the sum, now check the elements in the set and check if the count appears twice means its repeat and if 0 means the elemnt doies not exist

    TC - O(n^2), SC-O(n)

*/

// class Solution {
// public:
//     vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
//         int a = -1, b = -1;
//         unordered_map<int, int> m;
//         int sum = 0; 
//         for (auto row : grid) {
//             for (auto i : row) {
//                 m[i]++;
//                 sum++;
//             }
//         }

//         for (int i = 1; i <= sum; i++) {
//             if (m[i] == 2)
//                 a = i;
//             else if (m[i] == 0)
//                 b = i;
//         }
//         return {a, b};
//     }
// };