/*
* 413. Arithmetic Slices
* An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
Given an integer array nums, return the number of arithmetic subarrays of nums.
A subarray is a contiguous subsequence of the array.

Example 1:
Input: nums = [1,2,3,4]
Output: 3
Explanation: We have 3 arithmetic slices in nums: [1, 2, 3], [2, 3, 4] and [1,2,3,4] itself.

Example 2:
Input: nums = [1]
Output: 0
 
Constraints:
1 <= nums.length <= 5000
-1000 <= nums[i] <= 1000
*/

int numberOfArithmeticSlices(int* nums, int numsSize)
{
    if (numsSize < 3)
        return 0;
    int i;
    int sum, count, flag;
    for (i - 0; i < numsSize - 1; i++)
        nums[i] = nums[i + 1] - nums[i];
    flag = nums[0];
    count = 1;
    sum = 0;
    for (i = 1; i < numsSize - 1; i++)
        if (flag == nums[i])
            count++;
        else
        {
            if (count >= 2)
                sum += (count - 1) * (count) / 2;
            count = 1;
            flag = nums[i];
        }
    if (count > 1)
        sum += (count - 1) * (count) / 2;
    return sum;
}
/*
* 执行结果：通过
* 执行用时：0 ms, 在所有 C 提交中击败了100.00%的用户
* 内存消耗：5.8 MB, 在所有 C 提交中击败了61.39%的用户
*/