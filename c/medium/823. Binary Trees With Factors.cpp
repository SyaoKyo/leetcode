/* 823. Binary Trees With Factors
 * Given an array of unique integers, arr, where each integer arr[i] is strictly greater than 1.
 * We make a binary tree using these integers, and each number may be used for any number of times.
 * Each non-leaf node's value should be equal to the product of the values of its children.
 * Return the number of binary trees we can make. The answer may be too large so return the answer modulo 109 + 7.
 *
 * Example 1:
 * Input: arr = [2,4]
 * Output: 3
 * Explanation: We can make these trees: [2], [4], [4, 2, 2
 *
 * Example 2:
 * Input: arr = [2,4,5,10]
 * Output: 7
 * Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].
 *
 * Constraints:
 * 1 <= arr.length <= 1000
 * 2 <= arr[i] <= 109
 * All the values of arr are unique.
 * */

class Solution {
public:
    int numFactoredBinaryTrees(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        vector<long long> dp(arr.size());
        for (int i = 0; i < arr.size(); ++i) {
            dp[i] = 1;
            int left = 0, right = i - 1;
            while (left <= right) {
                while (left <= right && (long long)arr[left] * (long long)arr[right] > arr[i]) {
                    --right;
                }
                if (left <= right && (long long)arr[left] * (long long)arr[right] == arr[i]) {
                    if (left == right) {
                        dp[i] += dp[left] * dp[right];
                    } else {
                        dp[i] += dp[left] * dp[right] * 2;
                    }
                }
                ++left;
            }
        }
        long long sum = 0;
        for (auto num : dp) {
            sum += num;
        }
        return sum % (long long)(1e9 + 7);
    }
};

//时间52 ms，击败60.11%
//内存8.2 MB，击败91.1%