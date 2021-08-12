/*
* 739. Daily Temperatures
* Given an array of integers temperatures represents the daily temperatures, 
* return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature.
* If there is no future day for which this is possible, keep answer[i] == 0 instead.
*
* Example 1:
* Input: temperatures = [73,74,75,71,69,72,76,73]
* Output: [1,1,4,2,1,1,0,0]
*
* Example 2:
* Input: temperatures = [30,40,50,60]
* Output: [1,1,1,0]
*
* Example 3:
* Input: temperatures = [30,60,90]
* Output: [1,1,0]
*
* Constraints:
* 1 <= temperatures.length <= 10^5
* 30 <= temperatures[i] <= 100
*/

// 暴力
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize)
{
    // int ret[temperaturesSize];
    int* ret = (int*)malloc(sizeof(int) * temperaturesSize);
    memset(ret, 0, sizeof(int) * temperaturesSize);
    *returnSize = temperaturesSize;
    int i = 0;
    while (i < temperaturesSize - 1)
    {
        int j = i + 1;
        while (j < temperaturesSize)
        {
            if (temperatures[i] < temperatures[j])
            {
                ret[i] = j - i;
                break;
            }
            ++j;
        }
        ++i;
    }
    ret[i] = 0;
    return ret;
}
/*
* 执行结果：超出时间限制
*/

// 暴力（优化）
/*
* 对于温度列表中的每个元素 temperatures[i]，需要找到最小的下标 j，使得 i < j 且 temperatures[i] < temperatures[j]。
* 由于温度范围在 [30, 100] 之内，因此可以维护一个数组 next 记录每个温度第一次出现的下标。
* 数组 next 中的元素初始化为无穷大，在遍历温度列表的过程中更新 next 的值。反向遍历温度列表。
* 对于每个元素 temperatures[i]，在数组 next 中找到从 temperatures[i] + 1 到 100 中每个温度第一次出现的下标，
* 将其中的最小下标记为 warmerIndex，则 warmerIndex 为下一次温度比当天高的下标。如果 warmerIndex 不为无穷大，
* 则 warmerIndex - i 即为下一次温度比当天高的等待天数，最后令 next[temperatures[i]] = i。
* 为什么上述做法可以保证正确呢？因为遍历温度列表的方向是反向，当遍历到元素 temperatures[i] 时，
* 只有 temperatures[i] 后面的元素被访问过，即对于任意 t，当 next[t] 不为无穷大时，
* 一定存在 j 使得 temperatures[j] == t 且 i < j。又由于遍历到温度列表中的每个元素时都会更新数组 next 中的对应温度的元素值，
* 因此对于任意 t，当 next[t] 不为无穷大时，令 j = next[t]，则 j 是满足 temperatures[j] == t 且 i < j 的最小下标。
*/
const int MAX = ~(1 << 31);
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize)
{
    int* ret = (int*)malloc(sizeof(int) * temperaturesSize);
    int next[71];
    memset(ret, 0, sizeof(int) * temperaturesSize);
    int i = 0;
    while (i < 71)
        next[i++] = MAX;
    for (int i = temperaturesSize - 1; i >= 0; --i)
    {
        int warmerIndex = MAX;
        for (int t = temperatures[i] + 1 - 30; t <= 70; ++t)
            if (next[t] < warmerIndex)
                warmerIndex = next[t];
        if (warmerIndex < MAX)
            ret[i] = warmerIndex - i;
        next[temperatures[i] - 30] = i;
    }
    *returnSize = temperaturesSize;
    return ret;
}
/*
* 执行结果：通过
* 执行用时：472 ms, 在所有 C 提交中击败了45.25%的用户
* 内存消耗：51.7 MB, 在所有 C 提交中击败了53.23%的用户
*/

// 单调栈
/*
* 可以维护一个存储下标的单调栈，从栈底到栈顶的下标对应的温度列表中的温度依次递减。如果一个下标在单调栈里，则表示尚未找到下一次温度更高的下标。
* 正向遍历温度列表。对于温度列表中的每个元素 temperatures[i]，如果栈为空，则直接将 i 进栈，如果栈不为空，
* 则比较栈顶元素 prevIndex 对应的温度 temperatures[prevIndex] 和当前温度 temperatures[i]，
* 如果 temperatures[i] > temperatures[prevIndex]，则将 prevIndex 移除，并将 prevIndex 对应的等待天数赋为 i - prevIndex，
* 重复上述操作直到栈为空或者栈顶元素对应的温度小于等于当前温度，然后将 i 进栈。为什么可以在弹栈的时候更新 ans[prevIndex] 呢？
* 因为在这种情况下，即将进栈的 i 对应的 temperatures[i] 一定是 temperatures[prevIndex] 右边第一个比它大的元素，
* 试想如果 prevIndex 和 i 有比它大的元素，假设下标为 j，那么 prevIndex 一定会在下标 j 的那一轮被弹掉。
* 由于单调栈满足从栈底到栈顶元素对应的温度递减，因此每次有元素进栈时，会将温度更低的元素全部移除，
* 并更新出栈元素对应的等待天数，这样可以确保等待天数一定是最小的。
*/
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize)
{
    // printf("%d\n",temperaturesSize);
    // return temperatures;
    int* ret = (int*)malloc(sizeof(int) * temperaturesSize);
    memset(ret, 0, sizeof(int) * temperaturesSize);
    *returnSize = temperaturesSize;
    int stack[temperaturesSize], top = -1;
    for (int i = 0; i < temperaturesSize; i++)
    {
        int temperature = temperatures[i];
        while (top != -1 && temperature > temperatures[stack[top]])
        {
            int prevIndex = stack[top--];
            ret[prevIndex] = i - prevIndex;
        }
        stack[++top] = i;
    }
    return ret;
}



/*
* * 执行结果：通过
* 执行用时：412 ms, 在所有 C 提交中击败了68.02%的用户
* 内存消耗：51.5 MB, 在所有 C 提交中击败了62.57%的用户
*/