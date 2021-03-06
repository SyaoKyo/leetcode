/*
* 剑指 Offer 67. 把字符串转换成整数
* 写一个函数 StrToInt，实现把字符串转换成整数这个功能。不能使用 atoi 或者其他类似的库函数。
* 首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。
* 当我们寻找到的第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，作为该整数的正负号；
* 假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。
* 该字符串除了有效的整数部分之后也可能会存在多余的字符，这些字符可以被忽略，它们对于函数不应该造成影响。
* 注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换。
* 在任何情况下，若函数不能进行有效的转换时，请返回 0。
* 说明：
* 假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−2^31,  2^31 − 1]。
* 如果数值超过这个范围，请返回  INT_MAX (2^31 − 1) 或 INT_MIN (−2^31) 。
*
* 示例 1:
* 输入: "42"
* 输出: 42
*
* 示例 2:
* 输入: "   -42"
* 输出: -42
* 解释: 第一个非空白字符为 '-', 它是一个负号。我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。
*
* 示例 3:
* 输入: "4193 with words"
* 输出: 4193
* 解释: 转换截止于数字 '3' ，因为它的下一个字符不为数字。
*
* 示例 4:
* 输入: "words and 987"
* 输出: 0
* 解释: 第一个非空字符是 'w', 但它不是数字或正、负号。因此无法执行有效的转换。
*
* 示例 5:
* 输入: "-91283472332"
* 输出: -2147483648
* 解释: 数字 "-91283472332" 超过 32 位有符号整数范围。因此返回 INT_MIN (−2^31) 。
*/

const int MAX = ~(1 << 31);
const int MIN = (1 << 31);
int strToInt(char* str)
{
    // 删除前置空格和‘0’
    int strlens = strlen(str), i, j = 0;
    char s[strlens + 1];
    while (j < strlens && str[j] == ' ') ++j;
    while (j < strlens && (str[j] == '0' && str[j + 1] == '0')) ++j;
    strcpy(s, &str[j]);

    // 判断正负并删除后置非数字字符
    bool isPos;
    j = 0;
    strlens = strlen(s);
    if (s[0] == '-')
    {
        isPos = false;
        j++;
        while (j < strlens && (s[j] >= '0' && s[j] <= '9')) ++j;
    }
    else if (s[0] == '+')
    {
        isPos = true;
        j++;
        while (j < strlens && (s[j] >= '0' && s[j] <= '9')) ++j;
    }
    else
    {
        isPos = true;
        while (j < strlens && (s[j] >= '0' && s[j] <= '9')) ++j;
    }
    s[j] = '\0';

    // 保留有效数字
    char num[j + 1];
    strlens = strlen(s);
    if (s[0] == '-' || s[0] == '+')
        j = 1;
    else
        j = 0;
    while (j < strlens && s[j] == '0') ++j;
    strcpy(num, &s[j]);

    // 将字符依次转换为数字
    i = strlen(num) - 1;
    uint64_t tmp = 0, muti = 1;
    if (i < 10)
    {
        while (i >= 0)
        {
            if (num[i] >= '0' && num[i] <= '9')
            {
                tmp += (num[i] - '0') * muti;
                muti *= 10; 
                if (isPos)
                {
                    if (tmp >= MAX)
                        return MAX;
                }
                else
                {
                    if (tmp >= (uint)MIN)
                        return MIN;
                }
            }
            i--;
        }
        if (isPos)
            return (int)tmp;
        else
            return -(int)tmp;
    }
    else
    {
        if (isPos)
            return MAX;
        else
            return MIN;
    }

}
/*
* 执行结果：通过
* 执行用时：0 ms, 在所有 C 提交中击败了100.00%的用户
* 内存消耗：5.5 MB, 在所有 C 提交中击败了85.19%的用户
*/