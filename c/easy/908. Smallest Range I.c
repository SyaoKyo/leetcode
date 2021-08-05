/*
* 908. Smallest Range I
* You are given an integer array nums and an integer k.
* In one operation, you can choose any index i where 0 <= i < nums.
* length and change nums[i] to nums[i] + x where x is an integer from the range [-k, k]. 
* You can apply this operation at most once for each index i.
* The score of nums is the difference between the maximum and minimum elements in nums.
* Return the minimum score of nums after applying the mentioned operation at most once for each index in it.
*
* Example 1:
* Input: nums = [1], k = 0
* Output: 0
* Explanation: The score is max(nums) - min(nums) = 1 - 1 = 0.
* 
* Example 2:
* Input: nums = [0,10], k = 2
* Output: 6
* Explanation: Change nums to be [2, 8]. The score is max(nums) - min(nums) = 8 - 2 = 6.
* 
* Example 3:
* Input: nums = [1,3,6], k = 3
* Output: 0
* Explanation: Change nums to be [4, 4, 4]. The score is max(nums) - min(nums) = 4 - 4 = 0.
*  
* Constraints:
* 1 <= nums.length <= 10^4
* 0 <= nums[i] <= 10^4
* 0 <= k <= 10^4
*/


// 方法1：用快排找最值
int cmpfunc(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

int smallestRangeI(int* nums, int numsSize, int k)
{
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    return nums[numsSize - 1] - nums[0] - 2 * k < 0 ? 0 : nums[numsSize - 1] - nums[0] - 2 * k;
}
/*
* 执行结果：通过
* 执行用时：16 ms, 在所有 C 提交中击败了74.00%的用户
* 内存消耗：6.9 MB, 在所有 C 提交中击败了10.00%的用户
*/

// 方法2：顺序查找最值
int smallestRangeI(int* nums, int numsSize, int k)
{
    int max, min;
    max = min = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        if (max < nums[i])
            max = nums[i];
        if (min > nums[i])
            min = nums[i];
    }
    max -= k;
    min += k;
    if (max - min <= 0)
        return 0;
    else
        return max - min;
}
/*
* 执行结果：通过
* 执行用时：8 ms, 在所有 C 提交中击败了100.00%的用户
* 内存消耗：6.3 MB, 在所有 C 提交中击败了85.00%的用户
*/