/*
* 1480. Running Sum of 1d Array
* Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
Return the running sum of nums.

Example 1:
Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].

Example 2:
Input: nums = [1,1,1,1,1]
Output: [1,2,3,4,5]
Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].

Example 3:
Input: nums = [3,1,2,10,1]
Output: [3,4,6,16,17]

Constraints:
1 <= nums.length <= 1000
-10^6 <= nums[i] <= 10^6
*/

int* runningSum(int* nums, int numsSize, int* returnSize)
{
    *returnSize = numsSize;
    int i = 1;
    while (i < numsSize)
    {
        nums[i] += nums[i - 1];
        ++i;
    }
    return nums;
}

/*
* 执行结果：通过
* 执行用时：4 ms, 在所有 C 提交中击败了99.10%的用户
* 内存消耗：6.5 MB, 在所有 C 提交中击败了84.94%的用户
* 通过测试用例：53 / 53
*/