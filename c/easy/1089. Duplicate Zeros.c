/*
* 1089. Duplicate Zeros
* Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.
Note that elements beyond the length of the original array are not written. Do the above modifications to the input array in place and do not return anything.

Example 1:
Input: arr = [1,0,2,3,0,4,5,0]
Output: [1,0,0,2,3,0,0,4]
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]

Example 2:
Input: arr = [1,2,3]
Output: [1,2,3]
Explanation: After calling your function, the input array is modified to: [1,2,3]

Constraints:
1 <= arr.length <= 10^4
0 <= arr[i] <= 9
*/

// 爆破
void duplicateZeros(int* arr, int arrSize)
{
    int i = 0;
    while (i < arrSize)
    {
        if (arr[i] == 0)
        {
            int j = arrSize - 1;
            while (j > i)
                arr[j--] = arr[j - 1];
            arr[j] = 0;
            i++;
        }
        ++i;
    }
}
/*
* 执行结果：通过
* 执行用时：52 ms, 在所有 C 提交中击败了40.91%的用户
* 内存消耗：7.2 MB, 在所有 C 提交中击败了77.27%的用户
* 通过测试用例：30 / 30
*/

// 空间换时间（不满足要求）
void duplicateZeros(int* arr, int arrSize)
{
    int tmp[arrSize];
    memcpy(tmp, arr, arrSize * sizeof(int));
    int i = 0, j = 0;
    while (i + j < arrSize)
    {
        arr[i + j] = tmp[i];
        if (tmp[i] == 0)
        {
            ++j;
            if (i + j < arrSize)
                arr[i + j] = tmp[i];
        }
        ++i;
    }
}
/*
* 执行结果：通过
* 执行用时：12 ms, 在所有 C 提交中击败了98.86%的用户
* 内存消耗：7.3 MB, 在所有 C 提交中击败了71.59%的用户
* 通过测试用例：30 / 30
*/

// 优化
void duplicateZeros(int* arr, int arrSize)
{
    int possibleDups = 0;
    int length_ = arrSize - 1;
    // 统计0的数量
    for (int left = 0; left <= length_ - possibleDups; left++)
        if (arr[left] == 0)
        {
            if (left == length_ - possibleDups)
            {
                arr[length_] = 0;
                length_ -= 1;
                break;
            }
            possibleDups++;
        }
    int last = length_ - possibleDups;
    // 复写0
    for (int i = last; i >= 0; i--)
        if (arr[i] == 0)
        {
            arr[i + possibleDups] = 0;
            possibleDups--;
            arr[i + possibleDups] = 0;
        }
        else
            arr[i + possibleDups] = arr[i];
}
/*
* 执行结果：通过
* 执行用时：16 ms, 在所有 C 提交中击败了88.64%的用户
* 内存消耗：7.2 MB, 在所有 C 提交中击败了90.91%的用户
* 通过测试用例：30 / 30
*/
