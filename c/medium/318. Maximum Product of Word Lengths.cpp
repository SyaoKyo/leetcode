/* 318. Maximum Product of Word Lengths
 * Given a string array words, return the maximum value of length(word[i]) * length(word[j])
 * where the two words do not share common letters. If no such two words exist, return 0.
 *
 * Example 1:
 * Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
 * Output: 16
 * Explanation: The two words can be "abcw", "xtfn".
 *
 * Example 2:
 * Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
 * Output: 4
 * Explanation: The two words can be "ab", "cd".
 *
 * Example 3:
 * Input: words = ["a","aa","aaa","aaaa"]
 * Output: 0
 * Explanation: No such pair of words.
 *
 * Constraints:
 * 2 <= words.length <= 1000
 * 1 <= words[i].length <= 1000
 * words[i] consists only of lowercase English letters.
 */

class Solution {
public:
    int maxProduct(vector <string> &words) {
        int ans = 0;
        vector<int> maskList(words.size(), 0);
        for (int i = 0; i < words.size(); ++i) {
            for (auto c: words[i]) {
                maskList[i] |= 1 << (c - 'a');
            }
        }
        for (int i = 0; i < maskList.size(); ++i) {
            for (int j = i + 1; j < maskList.size(); ++j) {
                if (!(maskList[i] & maskList[j])) {
                    ans = max(ans, int(words[i].size() * words[j].size()));
                }
            }
        }
        return ans;
    }
};

// 时间80 ms，击败30.19%
// 内存21.6 MB，击败74.36%