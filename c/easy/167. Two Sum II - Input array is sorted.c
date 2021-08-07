/*
* 167. Two Sum II - Input array is sorted
* Given an array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number.
* Return the indices of the two numbers (1-indexed) as an integer array answer of size 2, where 1 <= answer[0] < answer[1] <= numbers.length.
* The tests are generated such that there is exactly one solution. You may not use the same element twice.
* Example 1:
* Input: numbers = [2,7,11,15], target = 9
* Output: [1,2]
* Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
* 
* Example 2:
* Input: numbers = [2,3,4], target = 6
* Output: [1,3]
* 
* Example 3:
* Input: numbers = [-1,0], target = -1
* Output: [1,2]
*  
* Constraints:
* 2 <= numbers.length <= 3 * 104
* -1000 <= numbers[i] <= 1000
* numbers is sorted in non-decreasing order.
* -1000 <= target <= 1000
* The tests are generated such that there is exactly one solution.
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 暴力破解（小优化）
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    *returnSize = 2;
    static int index[] = { 0,0 };
    for (int i = 0; i < numbersSize - 1 && numbers[i] <= target; i++)
    {
        int tar = target - numbers[i];
        for (int j = i + 1; j < numbersSize && numbers[j] <= tar; j++)
            if (numbers[i] + numbers[j] == target)
            {
                index[0] = i + 1;
                index[1] = j + 1;
                return index;
            }
    }
    return index;
}
/*
* 执行结果：通过
* 执行用时：164 ms, 在所有 C 提交中击败了19.35%的用户
* 内存消耗：6.4 MB, 在所有 C 提交中击败了96.77%的用户
*/

// 双指针
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    *returnSize = 2;
    static int index[2];
    index[0] = 0;
    index[1] = numbersSize - 1;
    int* left = &index[0], * right = &index[1];
    while (true)
    {
        if (numbers[*left] + numbers[*right] < target)
            (*left)++;
        else if (numbers[*left] + numbers[*right] > target)
            (*right)--;
        else
        {
            (*left)++;
            (*right)++;
            break;
        }
    }
    return index;
}

/*
* 执行结果：通过
* 执行用时：4 ms, 在所有 C 提交中击败了95.48%的用户
* 内存消耗：6.5 MB, 在所有 C 提交中击败了87.99%的用户
*/