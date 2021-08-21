/*
* 336. Palindrome Pairs
* Given a list of unique words, return all the pairs of the distinct indices (i, j) in the given list, 
so that the concatenation of the two words words[i] + words[j] is a palindrome.

Example 1:
Input: words = ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]]
Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]

Example 2:
Input: words = ["bat","tab","cat"]
Output: [[0,1],[1,0]]
Explanation: The palindromes are ["battab","tabbat"]

Example 3:
Input: words = ["a",""]
Output: [[0,1],[1,0]]
 
Constraints:
1 <= words.length <= 5000
0 <= words[i].length <= 300
words[i] consists of lower-case English letters.
*/

// 暴力破解 时间复杂度O(m*n^2) - n:字符串数量 m:字符串平均长度
bool isPalindrome(char* s)
{
    int i = 0, j = strlen(s) - 1;
    while (i < j)
        if (s[i++] != s[j--])
            return false;
    return true;
}

int** palindromePairs(char** words, int wordsSize, int* returnSize, int** returnColumnSizes)
{
    int n = wordsSize * (wordsSize - 1);
    int** a = (int**)malloc(sizeof(int*) * n);
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i)
    {
        a[i] = (int*)malloc(sizeof(int) * 2);
        (*returnColumnSizes)[i] = 2;
    }
    *returnSize = 0;
    for (int i = 0; i < wordsSize; ++i)
        for (int j = 0; j < wordsSize; ++j)
            if (i != j)
            {
                char tmp[601];
                tmp[0] = '\0';
                strcat(tmp, words[i]);
                strcat(tmp, words[j]);
                if (isPalindrome(tmp))
                {
                    a[*returnSize][0] = i;
                    a[*returnSize][1] = j;
                    ++(*returnSize);
                }
            }
    return a;
}
/*
* 执行结果：超出时间限制
*/