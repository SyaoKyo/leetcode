/*
* 541. Reverse String II
* Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.
* If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters,
* then reverse the first k characters and left the other as original.
* 
* Example 1:
* Input: s = "abcdefg", k = 2
* Output: "bacdfeg"
* 
* Example 2:
* Input: s = "abcd", k = 2
* Output: "bacd"
*
* Constraints:
* 1 <= s.length <= 10^4
* s consists of only lowercase English letters.
* 1 <= k <= 10^4
*/

// 递归
char* reverseStr(char* s, int k)
{
    int strlens = strlen(s);
    if (strlens < k)
    {
        int i = 0;
        while (i < strlens / 2)
        {
            s[i] += s[strlens - 1 - i];
            s[strlens - 1 - i] = s[i] - s[strlens - 1 - i];
            s[i] -= s[strlens - 1 - i];
            ++i;
        }
    }
    else if (strlens < 2 * k && strlens >= k)
    {
        int i = 0;
        while (i < k / 2)
        {
            s[i] += s[k - 1 - i];
            s[k - 1 - i] = s[i] - s[k - 1 - i];
            s[i] -= s[k - 1 - i];
            ++i;
        }
    }
    else
    {
        int i = 0;
        while (i < k / 2)
        {
            s[i] += s[k - 1 - i];
            s[k - 1 - i] = s[i] - s[k - 1 - i];
            s[i] -= s[k - 1 - i];
            ++i;
        }
        reverseStr((s + 2 * k), k);
    }
    return s;
}
/*
* 执行结果：通过
* 执行用时：0 ms, 在所有 C 提交中击败了100.00%的用户
* 内存消耗：5.8 MB, 在所有 C 提交中击败了90.26%的用户
*/

// 非递归
char* reverseStr(char* s, int k)
{
    int strlens = strlen(s);
    int i = 0;
    while (strlens - i > k * 2)
    {
        int j = i;
        int l = i + k - 1;
        int mid = i + k / 2;
        while (j < mid)
        {
            s[j] += s[l];
            s[l] = s[j] - s[l];
            s[j] -= s[l];
            ++j;
            --l;
        }
        i += 2 * k;
    }
    printf("%d,%d\n", strlens, i);
    if (strlens - i >= k)
    {
        int j = i;
        int l = i + k - 1;
        int mid = i + k / 2;
        while (j < mid)
        {
            s[j] += s[l];
            s[l] = s[j] - s[l];
            s[j] -= s[l];
            ++j;
            --l;
        }
    }
    else
    {
        int j = i;
        int l = strlens - 1;
        int mid = i + (l - j + 1) / 2;
        while (j != l && j < mid)
        {
            s[j] += s[l];
            s[l] = s[j] - s[l];
            s[j] -= s[l];
            ++j;
            --l;
        }
    }
    return s;
}
/*
* 执行结果：通过
* 执行用时：0 ms, 在所有 C 提交中击败了100.00%的用户
* 内存消耗：5.9 MB, 在所有 C 提交中击败了46.07%的用户
*/