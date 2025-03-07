// class Solution {
//     public:
//         // using inbuilt function
//         void nextPermutation(vector<int>& A) {
//             int pivot = -1;
//             int n = A.size();
    
//             // Step 1: Find the pivot (the first decreasing element from the end)
//             for (int i = n - 2; i >= 0; i--) {
//                 if (A[i] < A[i + 1]) {
//                     pivot = i;
//                     break; // Exit once the pivot is found
//                 }
//             }
    
//             // Step 2: If no pivot is found, the array is the last permutation
//             if (pivot == -1) {
//                 reverse(A.begin(), A.end());
//                 return;
//             }
    
//             // Step 3: Find the smallest element larger than A[pivot] to its right
//             for (int i = n - 1; i > pivot; i--) {
//                 if (A[i] > A[pivot]) {
//                     swap(A[i], A[pivot]);
//                     break;
//                 }
//             }
    
//             // Step 4: Reverse the elements to the right of the pivot
//             reverse(A.begin() + pivot + 1, A.end());
//             // next_permutation(nums.begin(),nums.end());
//             // int pivot = -1;
//             // int n = A.size();
//             // // 1st step - calculate or find the pivot element
//             // for (int i = n - 2; i >= 0; i--) {
//             //     // got the pivot element
//             //     if (A[i] < A[i + 1]) {
//             //         pivot = i;
//             //     }
//             // }
//             // // if there is no pivot element, then simply reverse the array
    
//             // if (pivot == -1) {
//             //     reverse(A.begin(), A.end());
//             //     return;
//             // }
    
//             // // 2nd step - find the bigger element from the current pivot element,
//             // or
//             // // Right most elemt whihc is bigger than  current pivot
//             // for (int i = n - 1; i > pivot; i--) {
//             //     if (A[i] > A[pivot]) {
//             //         swap(A[i], A[pivot]);
//             //         break;
//             //     }
//             // }
    
//             // // now swap the remaining element in increasing order
    
//             // // Step 4: Reverse the elements to the right of the pivot
//             // reverse(A.begin() + pivot + 1, A.end());
//         }
//     };