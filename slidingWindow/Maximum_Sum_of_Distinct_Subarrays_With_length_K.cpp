
// class Solution {
// public:
//     long long maximumSubarraySum(vector<int>& nums, int k) {
//         long long maxSum = 0;
//         int n = nums.size();
//         long long windSum = 0; // for storing the window some

//         unordered_map<int, int>
//             freq;  // to track the frequency of every elements
//         if (n < k) // if array contains less than k elemetns
//             return 0;
//         // calculate the first k sum
//         for (int i = 0; i <k; i++) {
//             windSum += nums[i];
//             // storing the frequency
//             freq[nums[i]]++;
//         }
//         /*
//         k=3
//         [4,1,4,1,2,3]
//             here 4 is repeating 2 times, map will store 4:2,
//             1:1, so the map size will be 2, andk is 3
//         */
//         if (freq.size() == k) { // basically we are checking for valid size,
//             maxSum = windSum;
//         }

//         // now check of window size
//         for (int i = k; i < n; i++) {
//             // first add new element from the right
//             windSum = windSum + nums[i];
//             // same store the right element into freq
//             freq[nums[i]]++;
//             // noew remove the i-k element from the letf
//             // i=3,k=3  = 0 , so nums[0], element will be removed

//             windSum = windSum - nums[i - k];
//             freq[nums[i - k]]--; // same removing the i-k th element
//             // if freq of any elemnt becomes 0, simply remove that element from
//             // the freq
//             if (freq[nums[i - k]] == 0) {
//                 freq.erase(nums[i - k]);
//             }

//             // now again check for valid size
//             if (freq.size() == k) {
//                 maxSum = max(maxSum, windSum);
//             }
//         }

//         return maxSum;

//         // this is brute force whihc will take (O(n^2))
//         // for (int i = 0; i <= n - k; i++) {
//         //     long long sum = 0;
//         //     bool isValid = true;
//         //     unordered_map<int, int> freq;
//         //     for (int j = i; j < i + k; j++) {
//         //         sum = sum + nums[j];
//         //         freq[nums[j]]++; // storing the frequency of all elements
//         //         if (freq[nums[j]] > 1) { // If any element repeats, it's no
//         //                                  // longer a valid window
//         //             isValid = false;
//         //             break; // exit early since we found a duplicate
//         //         }
//         //     }
//         //     if (isValid) {
//         //         maxSum = max(maxSum, sum);
//         //     }
//         // }
//         // return maxSum;
//     }
// };