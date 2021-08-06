/*
* 1550. Three Consecutive Odds
* Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.
*
* Example 1:
* Input: arr = [2,6,4,1]
* Output: false
* Explanation: There are no three consecutive odds.
* Example 2:
* Input: arr = [1,2,34,3,4,5,7,23,12]
* Output: true
* Explanation: [5,7,23] are three consecutive odds.
*  
* Constraints:
* 1 <= arr.length <= 1000
* 1 <= arr[i] <= 1000
*/

bool threeConsecutiveOdds(int* arr, int arrSize)
{
    for (int i=0:i<arrSize-2;i++)
        if (arr[i] * arr[i + 1] * arr[i + 2] % 2)
            return true;
    return false;
}

/*
* 执行结果：通过
* 执行用时：0 ms, 在所有 C 提交中击败了100.00%的用户
* 内存消耗：5.8 MB, 在所有 C 提交中击败了56.48%的用户
*/