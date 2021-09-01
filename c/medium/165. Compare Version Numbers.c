/*
* Given two version numbers, version1 and version2, compare them.
* Version numbers consist of one or more revisions joined by a dot '.'. Each revision consists of digits and may contain * * leading zeros. Every revision contains at least one character. Revisions are 0-indexed from left to right, with the * * * * leftmost revision being revision 0, the next revision being revision 1, and so on. For example 2.5.33 and 0.1 are valid * * version numbers.
* To compare version numbers, compare their revisions in left-to-right order. Revisions are compared using their integer * * value ignoring any leading zeros. This means that revisions 1 and 001 are considered equal. If a version number does not * specify a revision at an index, then treat the revision as 0. For example, version 1.0 is less than version 1.1 because * * their revision 0s are the same, but their revision 1s are 0 and 1 respectively, and 0 < 1.
* Return the following:
* If version1 < version2, return -1.
* If version1 > version2, return 1.
* Otherwise, return 0.
* 
* Example 1:
* Input: version1 = "1.01", version2 = "1.001"
* Output: 0
* Explanation: Ignoring leading zeroes, both "01" and "001" represent the same integer "1".
* 
* Example 2:
* Input: version1 = "1.0", version2 = "1.0.0"
* Output: 0
* Explanation: version1 does not specify revision 2, which means it is treated as "0".
* 
* Example 3:
* Input: version1 = "0.1", version2 = "1.1"
* Output: -1
* Explanation: version1's revision 0 is "0", while version2's revision 0 is "1". 0 < 1, so version1 < version2.
* 
* Example 4:
* Input: version1 = "1.0.1", version2 = "1"
* Output: 1
* 
* Example 5:
* Input: version1 = "7.5.2.4", version2 = "7.5.3"
* Output: -1
* 
* Constraints:
* 1 <= version1.length, version2.length <= 500
* version1 and version2 only contain digits and '.'.
* version1 and version2 are valid version numbers.
* All the given revisions in version1 and version2 can be stored in a 32-bit integer.
*/

int compareVersion(char * version1, char * version2)
{
    char *p1,*p2;
    int ver1,ver2;
    int strlens1=strlen(version1),strlens2=strlen(version2);
    int idx1,idx2;
    idx1=idx2=0;
    while (idx1<strlens1&&idx2<strlens2)
    {
        p1=&version1[idx1];
        p2=&version2[idx2];
        while (version1[idx1]>='0'&&version1[idx1]<='9') ++idx1;
        version1[idx1++]='\0';
        ver1=atoi(p1);
        while (version2[idx2]>='0'&&version2[idx2]<='9') ++idx2;
        version2[idx2++]='\0';
        ver2=atoi(p2);
        if (ver1<ver2)
            return -1;
        else if (ver1>ver2)
            return 1;
    }
    if (idx1>=strlens1&&idx2<strlens2)
    {
        while (idx2<strlens2)
        {
            p2=&version2[idx2];
            while (version2[idx2]>='0'&&version2[idx2]<='9') ++idx2;
            version2[idx2++]='\0';
            ver2=atoi(p2);
            if (0<ver2)
                return -1;
            else if (0>ver2)
                return 1;
        }
    }
    else if (idx2>=strlens2&&idx1<strlens1)
    {
        while (idx1<strlens1)
        {
            p1=&version1[idx1];
            while (version1[idx1]>='0'&&version1[idx1]<='9') ++idx1;
            version1[idx1++]='\0';
            ver1=atoi(p1);
            if (ver1<0)
                return -1;
            else if (ver1>0)
                return 1;
        }
    }
    else
        return 0;
    return 0;
}

/*
* 执行结果：通过
* 执行用时：0 ms, 在所有 C 提交中击败了100.00%的用户
* 内存消耗：5.5 MB, 在所有 C 提交中击败了47.49%的用户
* 通过测试用例：81 / 81
*/