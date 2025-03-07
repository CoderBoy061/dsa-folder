// 560. Subarray Sum Equals K 

// class Solution
// {
// public:
//     int subarraySum(vector<int> &a, int k)
//     {
//         int n = a.size(); // size of the array.

//         int left = 0, right = 0; // 2 pointers
//         int sum = a[0];
//         int maxLen = 0;
//         while (right < n)
//         {
//             // if sum > k, reduce the subarray from left
//             // until sum becomes less or equal to k:
//             while (left <= right && sum > k)
//             {
//                 sum -= a[left];
//                 left++;
//             }

//             // if sum = k, update the maxLen i.e. answer:
//             if (sum == k)
//             {
//                 maxLen = max(maxLen, right - left + 1);
//             }

//             // Move forward thw right pointer:
//             right++;
//             if (right < n)
//                 sum += a[right];
//         }

//         return maxLen;
//         // int n = nums.size();
//         // int count = 0;
//         // for (int i = 0; i= 0; < n; i++) {
//         //     int sum 
//         //     for (int j = i; j < n; j++) {
//         //         sum = sum + nums[j];
//         //         if (sum == k)
//         //             count++;
//         //     }
//         // }
//         // return count;
//     }
// }

// ;