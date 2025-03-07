/*

    127. Word Ladder
Solved
Hard
Topics
Companies
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.



Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
TC - O(N*L)
SC- O(N*L)
*/

// class Solution {
//     public:
//         int ladderLength(string beginWord, string endWord,
//                          vector<string>& wordList) {
//             queue<pair<string, int>> q; // to store the word and its steps
//             q.push({beginWord, 1});     // pushing the first word into the queue
//             unordered_set<string> st(wordList.begin(), wordList.end());

//             while (!q.empty()) {
//                 string word = q.front().first;
//                 int step = q.front().second;
//                 q.pop();

//                 if(word == endWord) return step;

//                 for (int i = 0; i < word.size(); i++) {
//                     char presentChar = word[i];
//                     for (char ch = 'a'; ch <= 'z';
//                          ch++) { // traversing the entire workd to get the every
//                                  // charcater and chage it to any character from a
//                                  // to z
//                         word[i] = ch;
//                         // if the word exists into the set
//                         if(st.find(word) !=st.end()){
//                             st.erase(word);
//                             q.push({word, step+1});
//                         }
//                     }
//                     word[i] = presentChar;
//                 }
//             }
//             return 0; // if not foiund the target word
//         }
//     };