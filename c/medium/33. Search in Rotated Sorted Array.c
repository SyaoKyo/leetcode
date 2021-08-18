/*
* 33. Search in Rotated Sorted Array
* There is an integer array nums sorted in ascending order (with distinct values).
* Prior to being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length)
* such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
* For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
* Given the array nums after the rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
* You must write an algorithm with O(log n) runtime complexity.
*
* Example 1:
* Input: nums = [4,5,6,7,0,1,2], target = 0
* Output: 4
* Example 2:
* Input: nums = [4,5,6,7,0,1,2], target = 3
* Output: -1
* Example 3:
* Input: nums = [1], target = 0
* Output: -1
*
* Constraints:
* 1 <= nums.length <= 5000
* -10^4 <= nums[i] <= 10^4
* All values of nums are unique.
* nums is guaranteed to be rotated at some pivot.
* -10^4 <= target <= 10^4
*/

int search(int* nums, int numsSize, int target)
{
    if (!numsSize)
        return -1;
    if (numsSize == 1)
        return nums[0] == target ? 0 : -1;
    int l = 0, r = numsSize - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[0] <= nums[mid])
            if (nums[0] <= target && target < nums[mid])
                r = mid - 1;
            else
                l = mid + 1;
        else
            if (nums[mid] < target && target <= nums[numsSize - 1])
                l = mid + 1;
            else
                r = mid - 1;
    }
    return -1;
}
/*
* 执行结果：通过
* 执行用时：4 ms, 在所有 C 提交中击败了69.83%的用户
* 内存消耗：5.9 MB, 在所有 C 提交中击败了48.90%的用户
*/

// 弃用
int search(int* nums, int numsSize, int target)
{
    int i = 0;
    int low, high, mid;
    switch (numsSize)
    {
    case 1:
        if (nums[0] == target)
            return 0;
        else
            return -1;
    case 2:
        if (nums[0] == target)
            return 0;
        else if (nums[1] == target)
            return 1;
        else
            return -1;
    default:
        while (i < numsSize - 1 && nums[i] < nums[i + 1])
            ++i;
        if (nums[i] >= target && nums[0] <= target)
        {
            low = 0, high = i, mid = (low + high) / 2;
            while (low < high && nums[mid] != target)
            {
                if (target <= nums[mid])
                {
                    high = mid;
                    mid = (low + mid) / 2;
                }
                else
                {
                    low = mid;
                    mid = (1 + mid + high) / 2;
                }
            }
        }
        else
        {
            if (i == numsSize - 1)
                return -1;
            low = i + 1, high = numsSize - 1, mid = (low + high) / 2;
            while (low < high && nums[mid] != target)
            {
                if (target <= nums[mid])
                {
                    high = mid;
                    mid = (low + mid) / 2;
                }
                else
                {
                    low = mid;
                    mid = (1 + mid + high) / 2;
                }
            }
        }
        if (low == high)
            return -1;
        return mid;
    }
}
/*
* 执行结果：超出时间限制
*/