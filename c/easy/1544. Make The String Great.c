/*
* 1544. Make The String Great
* Given a string s of lower and upper case English letters.
* A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where:
* 0 <= i <= s.length - 2
* s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.
* To make the string good, you can choose two adjacent characters that make the string bad and remove them. You can keep doing this until the string becomes good.
* Return the string after making it good. The answer is guaranteed to be unique under the given constraints.
* Notice that an empty string is also good.
*
* Example 1:
* Input: s = "leEeetcode"
* Output: "leetcode"
* Explanation: In the first step, either you choose i = 1 or i = 2, both will result "leEeetcode" to be reduced to "leetcode".
* 
* Example 2:
* Input: s = "abBAcC"
* Output: ""
* Explanation: We have many possible scenarios, and all lead to the same answer. For example:
* "abBAcC" --> "aAcC" --> "cC" --> ""
* "abBAcC" --> "abBA" --> "aA" --> ""
* 
* Example 3:
* Input: s = "s"
* Output: "s"
*  
* Constraints:
* 1 <= s.length <= 100
* s contains only lower and upper case English letters.
*/
char* makeGood(char* s)
{
    int top = -1, i = 0;
    char* stack = (char*)malloc(sizeof(char) * (strlen(s) + 1));
    while (i < strlen(s))
    {
        if (top == -1)
            stack[++top] = s[i];
        else
            if (s[i] >= 'a' && s[i] <= 'z')
                if (s[i] == stack[top] + 32)
                    top--;
                else
                    stack[++top] = s[i];
            else if (s[i] >= 'A' && s[i] <= 'Z')
                if (s[i] == stack[top] - 32)
                    top--;
                else
                    stack[++top] = s[i];
            else
                stack[++top] = s[i];
        i++;
    }
    stack[++top] = '\0';
    return stack;
}
/*
* 执行结果：通过
* 执行用时：0 ms, 在所有 C 提交中击败了100.00%的用户
*内存消耗：5.5 MB, 在所有 C 提交中击败了85.54%的用户
*/