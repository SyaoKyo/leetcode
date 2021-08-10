/*
* 791. Custom Sort String
* You are given two strings order and s. All the words of order are unique and were sorted in some custom order previously.
Permute the characters of s so that they match the order that order was sorted. More specifically, 
if a character x occurs before a character y in order, then x should occur before y in the permuted string.
Return any permutation of s that satisfies this property.

Example 1:
Input: order = "cba", s = "abcd"
Output: "cbad"
Explanation: 
"a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a". 
Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.

Example 2:
Input: order = "cbafg", s = "abcd"
Output: "cbad"

Constraints:
1 <= order.length <= 26
1 <= s.length <= 200
order and s consist of lowercase English letters.
All the characters of order are unique.
*/

char* customSortString(char* order, char* s)
{
    int strlens = strlen(order), strlent = strlen(s), k = 0;
    int i, j;
    i = 0;
    while (i < strlens)
    {
        j = 0;
        while (j < strlent)
        {
            if (order[i] == s[j])
            {
                if (j != k)
                {
                    s[j] += s[k];
                    s[k] = s[j] - s[k];
                    s[j] -= s[k];
                }
                k++;
            }
            ++j;
        }
        ++i;
    }
    return s;
}

/*
* 执行结果：通过
* 执行用时：0 ms, 在所有 C 提交中击败了100.00%的用户
* 内存消耗：5.3 MB, 在所有 C 提交中击败了93.62%的用户
*/