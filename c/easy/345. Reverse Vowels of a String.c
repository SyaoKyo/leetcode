/*
* 345. Reverse Vowels of a String
* Given a string s, reverse only all the vowels in the string and return it.
* The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both cases.
*
* Example 1:
* Input: s = "hello"
* Output: "holle"
*
* Example 2:
* Input: s = "leetcode"
* Output: "leotcede"
*
* Constraints:
* 1 <= s.length <= 3 * 10^5
* s consist of printable ASCII characters.
*/

char* reverseVowels(char* s)
{
    int i = 0, j = strlen(s) - 1;
    while (i < j)
    {
        while (i < j)
        {
            if ((s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') ||
                (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'))
                break;
            ++i;
        }
        while (i < j)
        {
            if ((s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u') ||
                (s[j] == 'A' || s[j] == 'E' || s[j] == 'I' || s[j] == 'O' || s[j] == 'U'))
                break;
            --j;
        }
        if (i < j)
        {
            s[i] += s[j];
            s[j] = s[i] - s[j];
            s[i++] -= s[j--];
        }
    }
    return s;
}

/*
* 执行结果：通过
* 执行用时：0 ms, 在所有 C 提交中击败了100.00%的用户
* 内存消耗：6.4 MB, 在所有 C 提交中击败了84.93%的用户
*/