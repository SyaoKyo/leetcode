/* 1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
 * You are given a rectangular cake of size h x w and two arrays of
 * integers horizontalCuts and verticalCuts where:
 * horizontalCuts[i] is the distance from the top of
 * the rectangular cake to the ith horizontal cut and similarly,
 * and verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.
 * Return the maximum area of a piece of cake after you cut at
 * each horizontal and vertical position provided in the arrays horizontalCuts and verticalCuts.
 * Since the answer can be a large number, return this modulo 10^9 + 7.
 *
 * Example 1:
 * Input: h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
 * Output: 4
 *
 * Example 2:
 * Input: h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]
 * Output: 6
 *
 * Example 3:
 * Input: h = 5, w = 4, horizontalCuts = [3], verticalCuts = [3]
 * Output: 9
 *
 * Constraints:
 * 2 <= h, w <= 10^9
 * 1 <= horizontalCuts.length <= min(h - 1, 10^5)
 * 1 <= verticalCuts.length <= min(w - 1, 10^5)
 * 1 <= horizontalCuts[i] < h
 * 1 <= verticalCuts[i] < w
 * All the elements in horizontalCuts are distinct.
 * All the elements in verticalCuts are distinct.
 */

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int maxH = 0, maxV = 0;
        horizontalCuts.emplace_back(h);
        verticalCuts.emplace_back(w);
        horizontalCuts.emplace_back(0);
        verticalCuts.emplace_back(0);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        for (int i = 0; i < horizontalCuts.size() - 1; ++i) {
            maxH = max(maxH, horizontalCuts[i + 1] - horizontalCuts[i]);
        }
        for (int i = 0; i < verticalCuts.size() - 1; ++i) {
            maxV = max(maxV, verticalCuts[i + 1] - verticalCuts[i]);
        }
        return (long)maxH * maxV % (int)(1e9 + 7);
    }
};

// 时间48 ms，击败99.11%
// 内存31.8 MB，击败41.59%