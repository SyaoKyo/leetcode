/*
* 1287. Element Appearing More Than 25% In Sorted Array
* Given an integer array sorted in non-decreasing order, 
* there is exactly one integer in the array that occurs more than 25% of the time, return that integer.
*
* Example 1:
* Input: arr = [1,2,2,6,6,6,6,7,10]
* Output: 6
* Example 2:
* Input: arr = [1,1]
* Output: 1
*
* Constraints:
* 1 <= arr.length <= 10^4
* 0 <= arr[i] <= 10^5
*/
int findSpecialInteger(int* arr, int arrSize)
{
    int sum = 1, i = 1;
    while (i < arrSize && 4 * sum <= arrSize)
    {
        if (arr[i] == arr[i - 1])
            ++sum;
        else
            sum = 1;
        ++i;
    }
    return arr[i - 1];
}

/*
* 执行结果：通过
* 执行用时：8 ms, 在所有 C 提交中击败了100.00%的用户
* 内存消耗：6.3 MB, 在所有 C 提交中击败了84.62%的用户
*/