/*
* 1018. Binary Prefix Divisible By 5
* You are given a binary array nums (0-indexed).
* We define xi as the number whose binary representation is the subarray nums[0..i] (from most-significant-bit to least-significant-bit).
* For example, if nums = [1,0,1], then x0 = 1, x1 = 2, and x2 = 5.
* Return an array of booleans answer where answer[i] is true if xi is divisible by 5.
* 
* Example 1:
* Input: nums = [0,1,1]
* Output: [true,false,false]
* Explanation: The input numbers in binary are 0, 01, 011; which are 0, 1, and 3 in base-10.
* Only the first number is divisible by 5, so answer[0] is true.
* 
* Example 2:
* Input: nums = [1,1,1]
* Output: [false,false,false]
* 
* Example 3:
* Input: nums = [0,1,1,1,1,1]
* Output: [true,false,false,false,true,false]
* 
* Example 4:
* Input: nums = [1,1,1,0,1]
* Output: [false,false,false,false,false]
*  
* Constraints:
* 1 <= nums.length <= 100000
* nums[i] is 0 or 1.
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* prefixesDivBy5(int* nums, int numsSize, int* returnSize)
{
    bool* answer = (bool*)malloc(sizeof(bool) * numsSize);
    *returnSize = numsSize;
    int num = 0, i = 0;
    while (i < numsSize)
    {
        num = ((num << 1) + nums[i]) % 5;
        if (num % 5)
            answer[i] = false;
        else
            answer[i] = true;
        ++i;
    }
    return answer;
}

/*
* 执行结果：通过
* 执行用时：28 ms, 在所有 C 提交中击败了83.72%的用户
* 内存消耗：10 MB, 在所有 C 提交中击败了95.35%的用户
*/