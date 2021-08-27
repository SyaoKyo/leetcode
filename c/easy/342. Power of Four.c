/*
* 342. Power of Four
* Given an integer n, return true if it is a power of four. Otherwise, return false.
An integer n is a power of four, if there exists an integer x such that n == 4x.

Example 1:
Input: n = 16
Output: true

Example 2:
Input: n = 5
Output: false

Example 3:
Input: n = 1
Output: true

Constraints:
-2^31 <= n <= 2^31 - 1
*/

bool isPowerOfFour(int n)
{
    if (n == 0)
        return false;
    double pow = log(n) / log(4);
    if (floor(pow + 0.5) == pow)
        return true;
    return false;
}
/*
* 执行结果：通过
* 执行用时：0 ms, 在所有 C 提交中击败了100.00%的用户
* 内存消耗：5.6 MB, 在所有 C 提交中击败了18.07%的用户
* 通过测试用例：1061 / 1061
*/