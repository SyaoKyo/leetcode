/**
 * 面试题 17.14. Smallest K LCCI
 * Design an algorithm to find the smallest K numbers in an array.
 * 
 * Example:
 * Input:  arr = [1,3,5,7,2,4,6,8], k = 4
 * Output:  [1,2,3,4]
 * 
 * Note:
 * 0 <= len(arr) <= 100000
 * 0 <= k <= min(100000, len(arr))
 */
int cmp(const void *a, const void *b)
{
    return (*(int*)a>*(int*)b?1:-1);
}

int* smallestK(int* arr, int arrSize, int k, int* returnSize)
{
    *returnSize=k;
    qsort(arr,arrSize,sizeof(int),cmp);
    return arr;
}

/**
 * 执行结果：通过
 * 执行用时：60 ms, 在所有 C 提交中击败了86.67%的用户
 * 内存消耗：13.8 MB, 在所有 C 提交中击败了75.15%的用户
 * 通过测试用例：29 / 29
 */