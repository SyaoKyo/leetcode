/*
* 704. Binary Search
* Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
* You must write an algorithm with O(log n) runtime complexity.
*
* Example 1:
* Input: nums = [-1,0,3,5,9,12], target = 9
* Output: 4
* Explanation: 9 exists in nums and its index is 4
*
* Example 2:
* Input: nums = [-1,0,3,5,9,12], target = 2
* Output: -1
* Explanation: 2 does not exist in nums so return -1
*
* Constraints:
* 1 <= nums.length <= 10^4
* -10^4 < nums[i], target < 10^4
* All the integers in nums are unique.
* nums is sorted in ascending order.
*/

int search(int* nums, int numsSize, int target)
{
    int low, high, mid;
    low = 0;
    high = numsSize - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (nums[mid] < target)
            low = mid + 1;
        else if (nums[mid] > target)
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}

/*
执行结果：通过
执行用时：28 ms, 在所有 C 提交中击败了96.90%的用户
内存消耗：6.9 MB, 在所有 C 提交中击败了76.56%的用户
通过测试用例：46 / 46
*/