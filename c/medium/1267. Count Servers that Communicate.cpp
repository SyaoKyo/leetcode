/*
 * You are given a map of a server center, represented as a m * n integer matrix grid,
 * where 1 means that on that cell there is a server and 0 means that it is no server.
 * Two servers are said to communicate if they are on the same row or on the same column.
 * Return the number of servers that communicate with any other server.
 *
 * Example 1:
 * Input: grid = [[1,0],[0,1]]
 * Output: 0
 * Explanation: No servers can communicate with others.
 *
 * Example 2:
 * Input: grid = [[1,0],[1,1]]
 * Output: 3
 * Explanation: All three servers can communicate with at least one other server.
 *
 * Example 3:
 * Input: grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
 * Output: 4
 * Explanation: The two servers in the first row can communicate with each other.
 * The two servers in the third column can communicate with each other.
 * The server at right bottom corner can't communicate with any other server.
 *
 * Constraints:
 * m == grid.length
 * n == grid[i].length
 * 1 <= m <= 250
 * 1 <= n <= 250
 * grid[i][j] == 0 or 1
 */
class Solution {
public:
    int countServers(vector<vector<int>> &grid) {
        int sum = 0;
        for (int i = 0; i < grid.size(); ++i) {
            sum += checkRow(grid, i);
        }
        for (int j = 0; j < grid[0].size(); ++j) {
            sum += checkCol(grid, j);
        }
        return sum;
    }

    int checkRow(vector<vector<int>> &grid, int rowIdx) {
        vector<int> colIdxes;
        int visitedSum = 0;
        for (int j = 0; j < grid[rowIdx].size(); ++j) {
            if (grid[rowIdx][j] > 0) {
                if (grid[rowIdx][j] == 2)
                    visitedSum++;
                colIdxes.emplace_back(j);
                grid[rowIdx][j] = 2;
            }
        }
        if (colIdxes.size() < 2) {
            for (auto colIdx: colIdxes) {
                grid[rowIdx][colIdx] = 1;
            }
        }
        return colIdxes.size() > 1 ? colIdxes.size() - visitedSum : 0;
    }

    int checkCol(vector<vector<int>> &grid, int colIdx) {
        vector<int> rowIdxes;
        int visitedSum = 0;
        for (int i = 0; i < grid.size(); ++i) {
            if (grid[i][colIdx] > 0) {
                if (grid[i][colIdx] == 2)
                    visitedSum++;
                rowIdxes.emplace_back(i);
                grid[i][colIdx] = 2;
            }
        }
        if (rowIdxes.size() < 2) {
            for (auto rowIdx: rowIdxes) {
                grid[rowIdx][colIdx] = 1;
            }
        }
        return rowIdxes.size() > 1 ? rowIdxes.size() - visitedSum : 0;
    }
};
//时间44 ms，击败86.6%
//内存22.5 MB，击败12.73%