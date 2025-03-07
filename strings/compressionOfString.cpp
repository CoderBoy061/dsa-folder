/*

443. String Compression
Medium
Topics
Companies
Hint
Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.

 

Example 1:

Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
Example 2:

Input: chars = ["a"]
Output: Return 1, and the first character of the input array should be: ["a"]
Explanation: The only group is "a", which remains uncompressed since it's a single character.
Example 3:

Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".


*/

/*

    Approach: 
    1. we can take a idx variable to track the index of the array while replacing 
    2. We can run a for loop for the entire string
    3. then nwe can take the cuurent character, means the 0th character and store it, for future comparison
    4. Take a count varibale to count the same character
    5. then we run another foor loop, from 0 to n-1, to check the individual charcater, if the ch or the chars[i] == same, then simply incement the count
    6. After that, we can get a count of 1 digit and 12 digit and more, as we have to reutn the digit as string, so we can convert them using to_str() fucntion
    7. we can check if the count is == 1, we can simply replace the first element of the current array, else we can add the character and the total count of that single character and replace it in the original array by the idx avriable and can increememnt the avariable
    8. As per the result we can simply reutrn the idx varibale

*/

// TC - O(n) 
// SC - O(1);


// class Solution {
// public:
//     int compress(vector<char>& chars) {
//         int n = chars.size();
//         int idx = 0;
//         for (int i = 0; i < n; i++) {
//             char ch = chars[i];
//             int count = 0;
//             // of the ch == the current character, then simply increement the
//             // count
//             while (i < n && chars[i] == ch) {
//                 count++;
//                 i++;
//             }

//             // now if the count is eqaul to 1 then simply return the character,
//             // else add the character and count on emore thing if the count is
//             // 12, then thgere will be 2 string "1", "2";

//             if (count == 1) {
//                 chars[idx++] = ch;
//             } else {
//                 chars[idx++] = ch;
//                 string st = to_string(count);
//                 for (auto it : st) {
//                     chars[idx++] = it;
//                 }
//             }
//             i--;
//         }
//         return idx;
//     }
// };