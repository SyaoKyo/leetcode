/*
* 787. Cheapest Flights Within K Stops
* There are n cities connected by some number of flights. 
You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.
You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

Example 1:
Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation: The graph is shown.
The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.

Example 2:
Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation: The graph is shown.
The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.

Constraints:
1 <= n <= 100
0 <= flights.length <= (n * (n - 1) / 2)
flights[i].length == 3
0 <= fromi, toi < n
fromi != toi
1 <= pricei <= 10^4
There will not be any multiple flights between two cities.
0 <= src, dst, k < n
src != dst
*/

// 动态规划 bellman ford算法
int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize, int src, int dst, int k) {
    int f[k + 2][n];
    memset(f, 0x7f, sizeof(f));
    f[0][src] = 0;
    for (int t = 1; t <= k + 1; ++t)
        for (int k = 0; k < flightsSize; k++)
        {
            int j = flights[k][0], i = flights[k][1], cost = flights[k][2];
            f[t][i] = fmin(f[t][i], f[t - 1][j] + cost);
        }
    int ans = 0x7f7f7f7f;
    for (int t = 1; t <= k + 1; ++t)
        ans = fmin(ans, f[t][dst]);
    return (ans == 0x7f7f7f7f ? -1 : ans);
}

/*
* 执行结果：通过
* 执行用时：20 ms, 在所有 C 提交中击败了95.10%的用户
* 内存消耗：7 MB, 在所有 C 提交中击败了100.00%的用户
*/