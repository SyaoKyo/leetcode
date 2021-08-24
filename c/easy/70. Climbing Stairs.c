/*
* 70. Climbing Stairs
* You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

Constraints:
1 <= n <= 45
*/

int climbStairs(int n)
{
    int a[46];
    a[0] = a[1] = 1;
    for (int i = 2; i <= 45; i++)
        a[i] = a[i - 1] + a[i - 2];
    return a[n];
}
/*
* 执行结果：通过
* 执行用时：0 ms, 在所有 C 提交中击败了100.00%的用户
* 内存消耗：5.3 MB, 在所有 C 提交中击败了94.83%的用户
*/