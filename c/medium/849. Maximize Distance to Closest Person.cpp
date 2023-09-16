/* 849. Maximize Distance to Closest Person
 * You are given an array representing a row of seats where seats[i] = 1 represents a person sitting in the ith seat,
 * and seats[i] = 0 represents that the ith seat is empty (0-indexed).
 * There is at least one empty seat, and at least one person sitting.
 * Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized.
 * Return that maximum distance to the closest person.
 *
 * Example 1:
 * Input: seats = [1,0,0,0,1,0,1]
 * Output: 2
 * Explanation:
 * If Alex sits in the second open seat (i.e. seats[2]), then the closest person has distance 2.
 * If Alex sits in any other open seat, the closest person has distance 1.
 * Thus, the maximum distance to the closest person is 2.
 *
 * Example 2:
 * Input: seats = [1,0,0,0]
 * Output: 3
 * Explanation:
 * If Alex sits in the last seat (i.e. seats[3]), the closest person is 3 seats away.
 * This is the maximum distance possible, so the answer is 3.
 *
 * Example 3:
 * Input: seats = [0,1]
 * Output: 1
 *
 * Constraints:
 * 2 <= seats.length <= 2 * 104
 * seats[i] is 0 or 1.
 * At least one seat is empty.
 * At least one seat is occupied.
*/

class Solution {
public:
    int maxDistToClosest(vector<int> &seats) {
        map<double, pair<int, int>, greater<>> allEmpty;    // 从大到小存放相距最远的座位位置
        int left = -1;  // 左指针
        double sum = 0; // 统计座位相距的最大距离
        for (int i = 0; i < seats.size(); ++i) {
            if (seats[i] == 0) {    // 如果座位空，则统计数+1
                sum++;
            } else {    // 如果座位不为空
                if (i > 0 && seats[i - 1] == 0) {   // 如果当前的座位的左边的座位为空（排除对最左边座位的判断）
                    if (left < 0)
                        allEmpty[sum] = pair<int, int>(left, i);
                    else
                        allEmpty[sum / 2.] = pair<int, int>(left, i);
                    sum = 0;
                }
                left = i;
            }
        }
        allEmpty[sum] = pair<int, int>(left, seats.size());
        auto leftIdx = allEmpty.begin()->second.first;  // 得到距离最大段的最左位置下标
        auto rightIdx = allEmpty.begin()->second.second;    // 得到距离最大段的最右的位置下标
        if (leftIdx < 0)    // 如果距离最大段在最左
            return rightIdx;
        if (rightIdx == seats.size())   // 如果距离最大段在最右
            return rightIdx - 1 - leftIdx;
        return min((rightIdx + leftIdx) / 2 - leftIdx, rightIdx - (rightIdx + leftIdx) / 2);    // 距离最大段在中间
    }
};
//时间8 ms，击败94.17%
//内存16.7 MB，击败40.83%