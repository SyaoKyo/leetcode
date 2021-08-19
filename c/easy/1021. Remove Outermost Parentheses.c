/*
* 1021. Remove Outermost Parentheses
* A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, 
* and + represents string concatenation.
* For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
* A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into
* s = A + B, with A and B nonempty valid parentheses strings.
* Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk,
* where Pi are primitive valid parentheses strings.
* Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.
*
* Example 1:
* Input: s = "(()())(())"
* Output: "()()()"
* Explanation:
* The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
* After removing outer parentheses of each part, this is "()()" + "()" = "()()()".
*
* Example 2:
* Input: s = "(()())(())(()(()))"
* Output: "()()()()(())"
* Explanation:
* The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
* After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".
*
* Example 3:
* Input: s = "()()"
* Output: ""
* Explanation:
* The input string is "()()", with primitive decomposition "()" + "()".
* After removing outer parentheses of each part, this is "" + "" = "".
*
* Constraints:
* 1 <= s.length <= 10^5
* s[i] is either '(' or ')'.
* s is a valid parentheses string.
*/

char* removeOuterParentheses(char* s)
{
    int sum = 0;
    int i = 0, j = 0, strlens = strlen(s);
    char* ret = (char*)malloc(sizeof(char) * (strlens + 1));
    while (i < strlens)
    {
        if (s[i] == '(')
        {
            if (sum++)
                ret[j++] = s[i];
            // ++sum;
        }
        else if (s[i] == ')')
        {
            // --sum;
            if (--sum)
                ret[j++] = s[i];
        }
        ++i;
    }
    ret[j] = '\0';
    return ret;
}
/*
* 执行结果：通过
* 执行用时：0 ms, 在所有 C 提交中击败了100.00%的用户
* 内存消耗：5.6 MB, 在所有 C 提交中击败了86.89%的用户
*/