/*
* 1573. Number of Ways to Split a String
* Given a binary string s (a string consisting only of '0's and '1's), we can split s into 3 non-empty strings s1, s2, s3 (s1+ s2+ s3 = s).
* Return the number of ways s can be split such that the number of characters '1' is the same in s1, s2, and s3.
* Since the answer may be too large, return it modulo 10^9 + 7.
*
* Example 1:
* Input: s = "10101"
* Output: 4
* Explanation: There are four ways to split s in 3 parts where each part contain the same number of letters '1'.
* "1|010|1"
* "1|01|01"
* "10|10|1"
* "10|1|01"
* 
* Example 2:
* Input: s = "1001"
* Output: 0
* 
* Example 3:
* Input: s = "0000"
* Output: 3
* Explanation: There are three ways to split s in 3 parts.
* "0|0|00"
* "0|00|0"
* "00|0|0"
* 
* Example 4:
* Input: s = "100100010100110"
* Output: 12
*  
* Constraints:
* 3 <= s.length <= 100000
* s[i] is '0' or '1'.
*/

// 暴力破解
int numWays(char* s)
{
    int sumOne = 0;
    for (int i = 0; i < strlen(s); i++)
        if (s[i] == '1')
            sumOne++;
    if (sumOne % 3)
        return 0;
    if (sumOne == 0)
        return ((strlen(s) - 2) * (strlen(s) - 1) / 2) % ((int)pow(10, 9) + 7);
    int splitOne = sumOne / 3;
    int indexEndOne[3], indexStartOne[3];
    int si, ei;
    sumOne = 0;
    si = ei = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '1')
        {
            ++sumOne;
            if (splitOne == 1)
                indexStartOne[si++] = indexEndOne[ei++] = i;
            else
            {
                if (sumOne % splitOne == 1)
                    indexStartOne[si++] = i;
                if (sumOne % splitOne == 0)
                    indexEndOne[ei++] = i;
            }
            if (si == 3 && ei == 3)
                break;
        }
    }
    int splitZero1 = indexStartOne[1] - indexEndOne[0];
    int splitZero2 = indexStartOne[2] - indexEndOne[1];
    return ((int64_t)splitZero1 * (int64_t)splitZero2) % ((int)pow(10, 9) + 7);
}

/*
* 执行结果：超出时间限制
*/

// 双指针
int numWays(char* s)
{
    int sumOne = 0;
    int strlens = strlen(s);
    for (int i = 0; i < strlens; i++)
        if (s[i] == '1')
            sumOne++;
    if (sumOne % 3)
        return 0;
    if (sumOne == 0)
        return ((int64_t)(strlens - 2) * (int64_t)(strlens - 1) / 2) % ((int)pow(10, 9) + 7);
    int splitOne = sumOne / 3;
    int indexEndOne[3], indexStartOne[3];
    int si, ei;
    sumOne = 0;
    si = ei = 0;
    for (int i = 0;; i++)
    {
        if (s[i] == '1')
        {
            ++sumOne;
            if (splitOne == 1)
                indexStartOne[si++] = indexEndOne[ei++] = i;
            else
            {
                if (sumOne % splitOne == 1)
                    indexStartOne[si++] = i;
                if (sumOne % splitOne == 0)
                    indexEndOne[ei++] = i;
            }
            if (si + ei >= 3)
                break;
        }
    }
    sumOne = 0;
    si = ei = 2;
    for (int i = strlens - 1;; i--)
    {
        if (s[i] == '1')
        {
            ++sumOne;
            if (splitOne == 1)
                indexStartOne[si--] = indexEndOne[ei--] = i;
            else
            {
                if (sumOne % splitOne == 0)
                    indexStartOne[si--] = i;
                if (sumOne % splitOne == 1)
                    indexEndOne[ei--] = i;
            }
            if (si + ei <= 1)
                break;
        }
    }
    int splitZero1 = indexStartOne[1] - indexEndOne[0];
    int splitZero2 = indexStartOne[2] - indexEndOne[1];
    return ((int64_t)splitZero1 * (int64_t)splitZero2) % ((int)pow(10, 9) + 7);
}
/*
* 执行结果：通过
* 执行用时：12 ms, 在所有 C 提交中击败了80.56%的用户
* 内存消耗：7.8 MB, 在所有 C 提交中击败了94.44%的用户
*/