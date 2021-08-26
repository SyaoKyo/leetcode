/*
* 881. Boats to Save People
* You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. 
Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.
Return the minimum number of boats to carry every given person.

Example 1:
Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)

Example 2:
Input: people = [3,2,2,1], limit = 3
Output: 3
Explanation: 3 boats (1, 2), (2) and (3)

Example 3:
Input: people = [3,5,3,4], limit = 5
Output: 4
Explanation: 4 boats (3), (3), (4), (5)

Constraints:
1 <= people.length <= 5 * 10^4
1 <= people[i] <= limit <= 3 * 10^4
*/

int cmp(const void* a, const void* b)
{
    return *(int*)a < *(int*)b ? 1 : -1;
}

int numRescueBoats(int* people, int peopleSize, int limit)
{
    qsort(people, peopleSize, sizeof(int), cmp);
    int sum = 0, i = 0, j = peopleSize - 1;
    while (i <= j)
    {
        if (people[i] + people[j] <= limit)
        {
            sum++;
            i++;
            j--;
        }
        else if (people[i] <= limit)
        {
            sum++;
            i++;
        }
    }
    return sum;
}

/*
* 执行结果：通过
* 执行用时：80 ms, 在所有 C 提交中击败了98.70%的用户
* 内存消耗：10.7 MB, 在所有 C 提交中击败了81.30%的用户
* 通过测试用例：78 / 78
*/