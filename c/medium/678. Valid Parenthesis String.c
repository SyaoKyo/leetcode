/*
* 678. Valid Parenthesis String
* Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.
The following rules define a valid string:
Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "(*)"
Output: true

Example 3:
Input: s = "(*))"
Output: true

Constraints:
1 <= s.length <= 100
s[i] is '(', ')' or '*'.
*/

bool checkValidString(char* s)
{
    int bakect_stack[100], star_stack[100];
    int bakect_top = -1, star_top = -1;
    int i, strlens = strlen(s);
    for (i = 0; i < strlens; i++)
    {
        if (s[i] == '(')
            bakect_stack[++bakect_top] = i;
        else if (s[i] == '*')
            star_stack[++star_top] = i;
        else if (s[i] == ')')
        {
            if (bakect_top > -1)
                bakect_top--;
            else if (star_top > -1)
                star_top--;
            else
                return false;
        }
    }
    while (bakect_top > -1)
    {
        if (star_top > -1 && bakect_stack[bakect_top] < star_stack[star_top])
        {
            bakect_top--;
            star_top--;
        }
        else
            return false;
    }
    return true;

}

/*
* 执行结果：通过
* 执行用时：0 ms, 在所有 C 提交中击败了100.00%的用户
* 内存消耗：5.3 MB, 在所有 C 提交中击败了90.00%的用户
* 通过测试用例：83 / 83
*/