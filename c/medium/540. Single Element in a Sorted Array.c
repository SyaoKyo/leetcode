/*
* 540. Single Element in a Sorted Array
* You are given a sorted array consisting of only integers where every element appears exactly twice, 
* except for one element which appears exactly once. Find this single element that appears only once.
* Follow up: Your solution should run in O(log n) time and O(1) space.
*
* Example 1:
* Input: nums = [1,1,2,3,3,4,4,8,8]
* Output: 2
*
* Example 2:
* Input: nums = [3,3,7,7,10,11,11]
* Output: 10
*
* Constraints:
* 1 <= nums.length <= 10^5
* 0 <= nums[i] <= 10^5
*/

int singleNonDuplicate(int* nums, int numsSize)
{
    for (int i = 0; i < numsSize - 1; i += 2)
        if (nums[i] != nums[i + 1])
            return nums[i];
    return nums[numsSize - 1];
}

/*
* 执行结果：通过
* 执行用时：4 ms, 在所有 C 提交中击败了98.02%的用户
* 内存消耗：6.4 MB, 在所有 C 提交中击败了71.78%的用户
*/