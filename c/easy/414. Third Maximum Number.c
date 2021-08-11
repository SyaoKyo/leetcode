/*
* 414. Third Maximum Number
* Given integer array nums, return the third maximum number in this array. If the third maximum does not exist, return the maximum number.
* 
* Example 1:
* Input: nums = [3,2,1]
* Output: 1
* Explanation: The third maximum is 1.
* Example 2:
* Input: nums = [1,2]
* Output: 2
* Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
* Example 3:
* Input: nums = [2,2,3,1]
* Output: 1
* Explanation: Note that the third maximum here means the third maximum distinct number.
* Both numbers with value 2 are both considered as second maximum.
*
* Constraints:
* 1 <= nums.length <= 10^4
* -2^31 <= nums[i] <= 2^31 - 1
* 
* Follow up: Can you find an O(n) solution?
*/

// 排序删重复后的结果
void quiksort(int a[], int low, int high)
{
    int i = low;
    int j = high;
    int temp = a[i];
    if (low < high)
    {
        while (i < j)
        {
            while ((a[j] <= temp) && (i < j))
                j--;
            a[i] = a[j];
            while ((a[i] >= temp) && (i < j))
                i++;
            a[j] = a[i];
        }
        a[i] = temp;
        quiksort(a, low, i - 1);
        quiksort(a, j + 1, high);
    }
    return;
}
int thirdMax(int* nums, int numsSize)
{
    quiksort(nums, 0, numsSize - 1);
    int a[numsSize];
    int i = 0, j = 0;
    a[j] = nums[i++];
    while (i < numsSize)
    {
        if (a[j] != nums[i])
            a[++j] = nums[i];
        ++i;
    }
    if (j < 2)
        return nums[0];
    int third_flag = 2, max;
    max = nums[0];
    i = 0;
    while (third_flag)
    {
        if (nums[i] == max)
            ++i;
        else
        {
            max = nums[i];
            ++i;
            --third_flag;
        }
    }
    return max;
}
/*
* 执行结果：通过
* 执行用时：56 ms, 在所有 C 提交中击败了8.36%的用户
* 内存消耗：5.9 MB, 在所有 C 提交中击败了93.31%的用户
*/

// 三指针遍历一遍（满足附加条件时间复杂度 O(n)）
int thirdMax(int* nums, int numsSize)
{
    if (numsSize < 3)
    {
        int max = nums[0] > nums[numsSize - 1] ? nums[0] : numsSize[numsSize - 1];
        return max;
    }
    int first_max, second_max, third_max;
    first_max = nums[0] > nums[1] ? nums[0] : nums[1];
    first_max = first_max > nums[2] ? first_max : nums[2];
    third_max = nums[0] < nums[1] ? nums[0] : nums[1];
    third_max = third_max < nums[2] ? third_max : nums[2];
    second_max = (first_max == nums[0] && third_max == nums[1]) || (first_max == nums[1] && third_max == nums[0]) ?
        nums[2] : ((first_max == nums[1] && third_max == nums[2]) || (first_max == nums[2] && third_max == nums[1]) ?
            nums[0] : nums[1]);
    for (int i = 3; i < numsSize; i++)
        if (nums[i] > first_max)
        {
            third_max = first_max == second_max ? third_max : second_max;
            second_max = first_max;
            first_max = nums[i];
        }
        else if (nums[i] != first_max && nums[i] != second_max && nums[i] > third_max)
        {
            third_max = first_max == second_max ? third_max : second_max;
            second_max = first_max == second_max ? nums[i] : (second_max > nums[i] ? second_max : nums[i]);
            third_max = third_max < nums[i] ? third_max : nums[i];
        }
        else if (second_max == third_max && nums[i] < third_max)
            third_max = nums[i];

    if (first_max == second_max || second_max == third_max)
        return first_max;
    return third_max;
}
/*
* 执行结果：通过
* 执行用时：0 ms, 在所有 C 提交中击败了100.00%的用户
* 内存消耗：5.9 MB, 在所有 C 提交中击败了88.96%的用户
*/