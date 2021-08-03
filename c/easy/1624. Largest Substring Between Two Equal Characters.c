/*
* 1624. Largest Substring Between Two Equal Characters
* Given a string s, return the length of the longest substring between two equal characters, excluding the two characters. If there is no such substring return -1.
* A substring is a contiguous sequence of characters within a string.
*
* Example 1:
* Input: s = "aa"
* Output: 0
* Explanation: The optimal substring here is an empty substring between the two 'a's.
*
* Example 2:
* Input: s = "abca"
* Output: 2
* Explanation: The optimal substring here is "bc".
*
* Example 3:
* Input: s = "cbzxy"
* Output: -1
* Explanation: There are no characters that appear twice in s.
*
* Example 4:
* Input: s = "cabbac"
* Output: 4
* Explanation: The optimal substring here is "abba". Other non-optimal substrings include "bb" and "".
*  
* Constraints:
* 1 <= s.length <= 300
* s contains only lowercase English letters.
*/
#include <cstdio>

int maxLengthBetweenEqualCharacters(char* s)
{
    int start = 0, end = strlen(s) - 1;
    int i, j;
    int maxLength = -1;
    i = start;
    while (i < end)
    {
        j = end;
        while (i < j && s[i] != s[j])
            --j;
        if (maxLength < j - i - 1)
            maxLength = j - i - 1;
        ++i;
    }
    return maxLength;
}

/*
* 执行结果：通过
* 执行用时：0 ms, 在所有 C 提交中击败了100.00%的用户
* 内存消耗：5.6 MB, 在所有 C 提交中击败了53.33%的用户
*/