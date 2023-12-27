/* 1094. Car Pooling
 * There is a car with capacity empty seats.
 * The vehicle only drives east (i.e., it cannot turn around and drive west).
 * You are given the integer capacity and an array trips where
 * trips[i] = [numPassengers_i, from_i, to_i] indicates that
 * the ith trip has numPassengers_i passengers and
 * the locations to pick them up and drop them off are from_i and to_i respectively.
 * The locations are given as the number of kilometers due east from the car's initial location.
 * Return true if it is possible to pick up and drop off all passengers for all the given trips,
 * or false otherwise.
 *
 * Example 1:
 * Input: trips = [[2,1,5],[3,3,7]], capacity = 4
 * Output: false
 *
 * Example 2:
 * Input: trips = [[2,1,5],[3,3,7]], capacity = 5
 * Output: true
 *
 * Constraints:
 * 1 <= trips.length <= 1000
 * trips[i].length == 3
 * 1 <= numPassengers_i <= 100
 * 0 <= from_i < to_i <= 1000
 * 1 <= capacity <= 10^5
 */

class Solution {
public:
    bool carPooling(vector<vector<int>> &trips, int capacity) {
        map<int, int> sumPassengers;
        for (const auto &trip: trips) {
            for (int i = trip[1]; i < trip[2]; i++) {
                sumPassengers[i] += trip[0];
                if (sumPassengers[i] > capacity) {
                    return false;
                }
            }
        }
        return true;
    }
};
// 时间320 ms，击败5.75%
// 内存12 MB，击败5.12%

class Solution {
public:
    bool carPooling(vector<vector<int>> &trips, int capacity) {
        map<int, int> actions;
        for (const auto &trip: trips) {
            actions[trip[1]] += trip[0];
            actions[trip[2]] -= trip[0];
        }

        int sumPassengers = 0;
        for (const auto &action: actions) {
            sumPassengers += action.second;
            if (sumPassengers > capacity) {
                return false;
            }
        }
        return true;
    }
};
// 时间12 ms，击败72.59%
// 内存10.7 MB，击败32.81%