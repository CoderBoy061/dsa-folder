// 2657. Find the Prefix Common Array of Two Arrays
// Medium
// Topics
// Companies
// Hint
// You are given two 0-indexed integer permutations A and B of length n.

// A prefix common array of A and B is an array C such that C[i] is equal to the count of numbers that are present at or before the index i in both A and B.

// Return the prefix common array of A and B.

// A sequence of n integers is called a permutation if it contains all integers from 1 to n exactly once.

// Example 1:

// Input: A = [1,3,2,4], B = [3,1,2,4]
// Output: [0,2,3,4]
// Explanation: At i = 0: no number is common, so C[0] = 0.
// At i = 1: 1 and 3 are common in A and B, so C[1] = 2.
// At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3.
// At i = 3: 1, 2, 3, and 4 are common in A and B, so C[3] = 4.
// Example 2:

// Input: A = [2,3,1], B = [3,1,2]
// Output: [0,1,3]
// Explanation: At i = 0: no number is common, so C[0] = 0.
// At i = 1: only 3 is common in A and B, so C[1] = 1.
// At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3.

/*
    Brute Force : We can traverse the both array and check for common element, if the element are equal then we can store that count inside and new array, whihc will be the ans array. We can use a unordered_set to store the same element.
    So, the actaul approach will be, traverse the evetire array, and store the ith element of the first array inside set, then we can run a second loop to check if the element is already present in the set or not? basically we will check the count. If the count id greater than 1 only then we will store that count inside the array


*/

// class Solution {
// public:
//     vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
//         int n = A.size();
//         vector<int> ans(n, 0);

//         // TC- O(n2) + O(1) for inertion
//         // running the loop for n leght
//         for (int i = 0; i < n; i++) {
//             unordered_set<int> seen;

//             // run the looop to check every element inside A array
//             for (int j = 0; j <= i; j++) {
//                 seen.insert(A[j]);
//             }

//             // now run the same loop for B as well
//             for (int j = 0; j <= i; j++) {
//                 // means the same element is already present in the set, the
//                 // simply store the count of that element and the index
//                 if (seen.count(B[j])) {
//                     ans[i]++;
//                 }
//             }
//         }
//         return ans;
//     }
// };

/*

    Optimal Approach - Now we have to remove a loop, because we are taking O(n^2), now we will try to solve the problem in one pass

    1. Traverse the array from 0 to n
    2. Check the count for every array inside set, if the count if 0, means the element is not present then simply insert that element
    2. If the element is already present than take a count variable and increment that count variable in every intreation


*/

// class Solution {
// public:
//     vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
//         int n = A.size();
//         vector<int> ans(n, 0);
//         unordered_set<int> seen;
//         int count = 0;

//         // Optimal Approach
//         for (int i = 0; i < n; i++) {

//             if (seen.count(A[i])) {
//                 count++;
//             } else {
//                 seen.insert(A[i]);
//             }

//             if (seen.count(B[i])) {
//                 count++;
//             } else {
//                 seen.insert(B[i]);
//             }

//             ans[i] = count;
//         }
//         return ans;
//     }
// };