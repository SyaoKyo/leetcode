/*
* 1221. Split a String in Balanced Strings
* Balanced strings are those that have an equal quantity of 'L' and 'R' characters.
* Given a balanced string s, split it in the maximum amount of balanced strings.
* Return the maximum amount of split balanced strings.
*
* Example 1:
* Input: s = "RLRRLLRLRL"
* Output: 4
* Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.
*
* Example 2:
* Input: s = "RLLLLRRRLR"
* Output: 3
* Explanation: s can be split into "RL", "LLLRRR", "LR", each substring contains same number of 'L' and 'R'.
*
* Example 3:
* Input: s = "LLLLRRRR"
* Output: 1
* Explanation: s can be split into "LLLLRRRR".
*
* Example 4:
* Input: s = "RLRRRLLRLL"
* Output: 2
* Explanation: s can be split into "RL", "RRRLLRLL", since each substring contains an equal number of 'L' and 'R'
*
* Constraints:
* 1 <= s.length <= 1000
* s[i] is either 'L' or 'R'.
* s is a balanced string.
*/

int balancedStringSplit(char* s)
{
    int num_l = 0, num_r = 0, sum = 0;
    int strlens = strlen(s), i = 0;
    while (i < strlens)
    {
        if (s[i] == 'R')
            ++num_r;
        else if (s[i] == 'L')
            ++num_l;
        if (num_l == num_r)
        {
            num_l = num_r = 0;
            ++sum;
        }
        ++i;
    }
    return sum;
}

/*
* 执行结果：通过
* 执行用时：0 ms, 在所有 C 提交中击败了100.00%的用户
* 内存消耗：5.4 MB, 在所有 C 提交中击败了72.07%的用户
* 通过测试用例：40 / 40
*/