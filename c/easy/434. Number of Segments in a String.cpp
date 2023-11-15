/* 434. Number of Segments in a String
 * Given a string s, return the number of segments in the string.
 * A segment is defined to be a contiguous sequence of non-space characters.
 * Example 1:
 * Input: s = "Hello, my name is John"
 * Output: 5
 * Explanation: The five segments are ["Hello,", "my", "name", "is", "John"]
 *
 * Example 2:
 * Input: s = "Hello"
 * Output: 1
 *
 * Constraints:
 * 0 <= s.length <= 300
 * s consists of lowercase and uppercase English letters, digits,
 * or one of the following characters "!@#$%^&*()_+-=',.:".
 * The only space character in s is ' '.
 */

class Solution {
public:
    int countSegments(string &s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            // 第一个字符不是空格的情况
            if (i == 0 && s[i] != ' ') {
                count++;
            }
            // 只要s[i]是空格，s[i+1]不是空格，count就加1
            if (i + 1 < s.size() && s[i] == ' ' && s[i + 1] != ' ') {
                count++;
            }
        }
        return count;
    }
};

// 时间0 ms，击败100%
// 内存6.3 MB，击败49.6%