/*
* 470. Implement Rand10() Using Rand7()
* Given the API rand7() that generates a uniform random integer in the range [1, 7], write a function rand10() that generates a uniform random integer in the range [1, 10]. 
* You can only call the API rand7(), and you shouldn't call any other API. Please do not use a language's built-in random API.
* Each test case will have one internal argument n, the number of times that your implemented function rand10() will be called while testing.
* Note that this is not an argument passed to rand10().
* Follow up:
* What is the expected value for the number of calls to rand7() function?
* Could you minimize the number of calls to rand7()?
*
* Example 1:
* Input: n = 1
* Output: [2]
*
* Example 2:
* Input: n = 2
* Output: [2,8]
*
* Example 3:
* Input: n = 3
* Output: [3,8,10]
*
* Constraints:
* 1 <= n <= 10^5
*/
// 拒绝采样法
int rand10()
{
    int a, b, num;
    while (1)
    {
        a = rand7();
        b = rand7();
        num = (a - 1) * 7 + b; // rand 49
        if (num <= 40)
            return num % 10 + 1; // 拒绝采样

        a = num - 40; // rand 9
        b = rand7();
        num = (a - 1) * 7 + b; // rand 63
        if (num <= 60)
            return num % 10 + 1;

        a = num - 60; // rand 3
        b = rand7();
        num = (a - 1) * 7 + b; // rand 21
        if (num <= 20)
            return num % 10 + 1;
    }
}

/*
执行结果：通过
执行用时：56 ms, 在所有 C 提交中击败了96.94%的用户
内存消耗：11.9 MB, 在所有 C 提交中击败了60.26%的用户
通过测试用例：12 / 12
*/