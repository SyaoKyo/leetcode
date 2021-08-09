/*
* 224. Basic Calculator
* Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.
* Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
*
* Example 1:
* Input: s = "1 + 1"
* Output: 2
*
* Example 2:
* Input: s = " 2-1 + 2 "
* Output: 3
*
* Example 3:
* Input: s = "(1+(4+5+2)-3)+(6+8)"
* Output: 23
*  
* Constraints:
* 1 <= s.length <= 3 * 100000
* s consists of digits, '+', '-', '(', ')', and ' '.
* s represents a valid expression.
* '+' is not used as a unary operation.
* '-' could be used as a unary operation but it has to be followed by parentheses.
* Every number and running calculation will fit in a signed 32-bit integer.
*/
int calculate(char* s) {
    int n = strlen(s);
    int ops[n], top = 0;
    int sign = 1;
    ops[top++] = sign;

    int ret = 0;
    int i = 0;
    while (i < n) {
        if (s[i] == ' ') {
            i++;
        }
        else if (s[i] == '+') {
            sign = ops[top - 1];
            i++;
        }
        else if (s[i] == '-') {
            sign = -ops[top - 1];
            i++;
        }
        else if (s[i] == '(') {
            ops[top++] = sign;
            i++;
        }
        else if (s[i] == ')') {
            top--;
            i++;
        }
        else {
            long num = 0;
            while (i < n && s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + s[i] - '0';
                i++;
            }
            ret += sign * num;
        }
    }
    return ret;
}
/*
* 执行结果：通过
* 执行用时：0 ms, 在所有 C 提交中击败了100.00%的用户
* 内存消耗：7.4 MB, 在所有 C 提交中击败了46.90%的用户
*/