/*
* 600. Non-negative Integers without Consecutive Ones
* Given a positive integer n, return the number of the integers in the range [0, n] 
* whose binary representations do not contain consecutive ones.
*
* Example 1:
* Input: n = 5
* Output: 5
* Explanation:
* Here are the non-negative integers <= 5 with their corresponding binary representations:
* 0 : 0
* 1 : 1
* 2 : 10
* 3 : 11
* 4 : 100
* 5 : 101
* Among them, only integer 3 disobeys the rule (two consecutive ones) and the other 5 satisfy the rule. 
*
* Example 2:
* Input: n = 1
* Output: 2
* Example 3:
* Input: n = 2
* Output: 3
*
* Constraints:
* 1 <= n <= 10^9
*/
int findIntegers(int n)
{
    char str_num[31];
    int sum=n+1;
    for (int i=0;i<=n;i++)
    { 
        sprintf(str_num,"%x",i);
        int strlens=strlen(str_num);
        for (int j=0;j<strlens;j++)
        {
            if (str_num[j]=='3'||str_num[j]=='6'||str_num[j]=='7'||str_num[j]=='b'||
            str_num[j]=='c'||str_num[j]=='d'||str_num[j]=='e'||str_num[j]=='f')
            {
                --sum;
                break;
            }
            if (str_num[j]=='1'||str_num[j]=='3'||str_num[j]=='5'||str_num[j]=='7'||
            str_num[j]=='9'||str_num[j]=='b'||str_num[j]=='d'||str_num[j]=='f')
            {
                if (str_num[j+1]=='8'||str_num[j+1]=='9'||str_num[j+1]=='a'||str_num[j+1]=='b'||
                str_num[j+1]=='c'||str_num[j+1]=='d'||str_num[j+1]=='e'||str_num[j+1]=='f')
                {
                    --sum;
                    break;
                }
            }
        }
    }
    return sum;
}
/*执行结果：超出时间限制*/

// 数位DP
int findIntegers(int n)
{
    int dp[31];
    dp[0] = dp[1] = 1;
    for (int i = 2; i < 31; ++i) 
        dp[i] = dp[i - 1] + dp[i - 2];
    int pre = 0, res = 0;
    for (int i = 29; i >= 0; --i) 
    {
        int val = 1 << i;
        if ((n & val) != 0) 
        {
            res += dp[i + 1];
            if (pre == 1) 
                break;
            pre = 1;
        } 
        else 
            pre = 0;
        if (i == 0) 
            ++res;
    }
    return res;
}
/*
* 执行结果：通过
* 执行用时：4 ms, 在所有 C 提交中击败了28.57%的用户
* 内存消耗：5.3 MB, 在所有 C 提交中击败了92.86%的用户
* 通过测试用例：527 / 527
*/
