/*
* 524. Longest Word in Dictionary through Deleting
* Given a string s and a string array dictionary, return the longest string in the dictionary that can be formed by deleting some of the given string characters. 
* If there is more than one possible result, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.
*
* Example 1:
* Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
* Output: "apple"
*
* Example 2:
* Input: s = "abpcplea", dictionary = ["a","b","c"]
* Output: "a"
*
* Constraints:
* 1 <= s.length <= 1000
* 1 <= dictionary.length <= 1000
* 1 <= dictionary[i].length <= 1000
* s and dictionary[i] consist of lowercase English letters.
*/

int cmp(const void* a, const void* b)
{
    return strcmp(*((char**)a), *((char**)b));
}
int cmplen(const void* a, const void* b)
{
    return strlen(*((char**)a)) < strlen(*((char**)b));
}

char* findLongestWord(char* s, char** dictionary, int dictionarySize)
{
    qsort(dictionary, dictionarySize, sizeof(char*), cmp);
    qsort(dictionary, dictionarySize, sizeof(char*), cmplen);
    int strlens = strlen(s);
    int strlendic;
    int i, j, n;
    for (n = 0; n < dictionarySize; n++)
    {
        strlendic = strlen(dictionary[n]);
        for (i = j = 0; i < strlens && j < strlendic;)
        {
            if (s[i] == dictionary[n][j])
            {
                i++;
                j++;
            }
            else
                i++;
        }
        if (j == strlendic)
            return dictionary[n];
    }
    return "";
}

/*
* 执行结果：通过
* 执行用时：32 ms, 在所有 C 提交中击败了78.90%的用户
* 内存消耗：10 MB, 在所有 C 提交中击败了65.14%的用户
* 通过测试用例：31 / 31
*/