/*
* 788. Rotated Digits
* An integer x is a good if after rotating each digit individually by 180 degrees, we get a valid number that is different from x. 
* Each digit must be rotated - we cannot choose to leave it alone.
* A number is valid if each digit remains a digit after rotation. For example:
* 0, 1, and 8 rotate to themselves,
* 2 and 5 rotate to each other (in this case they are rotated in a different direction, in other words, 2 or 5 gets mirrored),
* 6 and 9 rotate to each other, and
* the rest of the numbers do not rotate to any other number and become invalid.
* Given an integer n, return the number of good integers in the range [1, n].
*
* Example 1:
* Input: n = 10
* Output: 4
* Explanation: There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
* Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.
* 
* Example 2:
* Input: n = 1
* Output: 0
* 
* Example 3:
* Input: n = 2
* Output: 1
*  
* Constraints:
* 1 <= n <= 10000
*/
char changeNum(char num)
{
    switch (num)
    {
    case '0':return '0';
    case '1':return '1';
    case '2':return '5';
    case '5':return '2';
    case '6':return '9';
    case '8':return '8';
    case '9':return '6';
    default:return '-';
    }
}
bool isGoodNumber(int n)
{
    int i;
    char num[6], temp[6];
    sprintf(num, "%d", n);
    for (i = 0; i < strlen(num); i++)
        temp[i] = changeNum(num[i]);
    temp[i] = '\0';
    if (!strcmp(temp, num))
        return false;
    else
        for (i = 0; i < strlen(num); i++)
            if (temp[i] == '-')
                return false;
    return true;


}
int rotatedDigits(int n)
{
    int i, sum = 0;
    for (i = 1; i <= n; i++)
        if (isGoodNumber(i))
            sum++;
    return sum;
}

/*
* 执行结果：通过
* 执行用时：24 ms, 在所有 C 提交中击败了7.46%的用户
* 内存消耗：5.5 MB, 在所有 C 提交中击败了23.88%的用户
*/