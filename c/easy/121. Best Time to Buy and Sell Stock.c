/*
* 121. Best Time to Buy and Sell Stock
* You are given an array prices where prices[i] is the price of a given stock on the i-th day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

Constraints:
1 <= prices.length <= 10^5
0 <= prices[i] <= 10^4
*/

int maxProfit(int* prices, int pricesSize)
{
    int profit = 0, min_price = prices[0];
    for (int i = 1; i < pricesSize; i++)
    {
        if (profit < prices[i] - min_price)
            profit = prices[i] - min_price;
        if (min_price > prices[i])
            min_price = prices[i];
    }
    return profit;
}
/*
* 执行结果：通过
* 执行用时：116 ms, 在所有 C 提交中击败了85.99%的用户
* 内存消耗：12.6 MB, 在所有 C 提交中击败了84.86%的用户
*/


// 暴力破解
 int maxProfit(int* prices, int pricesSize)
 {
     int profit=0;
     for (int i=0;i<pricesSize-1;i++)
     {
         int m=prices[i+1]-prices[i];
         for (int j=i+2;j<pricesSize;j++)
         {
             if (m<prices[j]-prices[i])
                 m=prices[j]-prices[i];
         }
         if (profit<m)
             profit=m;
     }
     return profit;
 }
 /*
 * 执行结果：超时
 */