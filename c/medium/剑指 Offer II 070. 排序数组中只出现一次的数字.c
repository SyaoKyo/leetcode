/*
* 剑指 Offer II 070. 排序数组中只出现一次的数字
* 给定一个只包含整数的有序数组 nums ，每个元素都会出现两次，唯有一个数只会出现一次，请找出这个唯一的数字。

示例 1:
输入: nums = [1,1,2,3,3,4,4,8,8]
输出: 2

示例 2:
输入: nums =  [3,3,7,7,10,11,11]
输出: 10

提示:
1 <= nums.length <= 10^5
0 <= nums[i] <= 10^5
*/

int singleNonDuplicate(int* nums, int numsSize)
{
    int i = 0;
    while (i < numsSize - 1)
    {
        if (nums[i] != nums[i + 1])
            return nums[i];
        i += 2;
    }
    return nums[numsSize - 1];
}

/*
* 执行结果：通过
* 执行用时：4 ms, 在所有 C 提交中击败了100.00%的用户
* 内存消耗：6.5 MB, 在所有 C 提交中击败了51.85%的用户
*/