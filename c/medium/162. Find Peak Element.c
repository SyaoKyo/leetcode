/*
* 162. Find Peak Element
* A peak element is an element that is strictly greater than its neighbors.
* Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
* You may imagine that nums[-1] = nums[n] = -∞.
* You must write an algorithm that runs in O(log n) time.
*
* Example 1:
* Input: nums = [1,2,3,1]
* Output: 2
* Explanation: 3 is a peak element and your function should return the index number 2.
*
* Example 2:
* Input: nums = [1,2,1,3,5,6,4]
* Output: 5
* Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
*
* Constraints:
* 1 <= nums.length <= 1000
* -2^31 <= nums[i] <= 2^31 - 1
* nums[i] != nums[i + 1] for all valid i.
*/
int findPeakElement(int* nums, int numsSize)
{
    if (numsSize == 1)
        return 0;
    if (nums[0] > nums[1])
        return 0;
    for (int i = 1; i < numsSize - 1; i++)
    {
        if (nums[i - 1] < nums[i] && nums[i + 1] < nums[i])
            return i;
    }
    if (nums[numsSize - 2] < nums[numsSize - 1])
        return numsSize - 1;
    return 0;
}

/*
* 执行结果：通过
* 执行用时：0 ms, 在所有 C 提交中击败了100.00%的用户
* 内存消耗：5.7 MB, 在所有 C 提交中击败了49.36%的用户
* 通过测试用例：63 / 63
*/