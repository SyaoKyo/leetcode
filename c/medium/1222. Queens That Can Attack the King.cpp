/* 1222. Queens That Can Attack the King
 * On a 0-indexed 8 x 8 chessboard, there can be multiple black queens ad one white king.
 * You are given a 2D integer array queens where queens[i] = [x_Queeni, y_Queeni]
 * represents the position of the ith black queen on the chessboard.
 * You are also given an integer array king of length 2 where king = [x_King, y_King]
 * represents the position of the white king.
 * Return the coordinates of the black queens that can directly attack the king. You may return the answer in any order.
 *
 * Example 1:
 * Input: queens = [[0,1],[1,0],[4,0],[0,4],[3,3],[2,4]], king = [0,0]
 * Output: [[0,1],[1,0],[3,3]]
 * Explanation: The diagram above shows the three queens that can directly attack the king
 * and the three queens that cannot attack the king (i.e., marked with red dashes).
 *
 * Example 2:
 * Input: queens = [[0,0],[1,1],[2,2],[3,4],[3,5],[4,4],[4,5]], king = [3,3]
 * Output: [[2,2],[3,4],[4,4]]
 * Explanation: The diagram above shows the three queens that can directly attack the king
 * and the three queens that cannot attack the king (i.e., marked with red dashes).
 *
 * Constraints:
 * 1 <= queens.length < 64
 * queens[i].length == king.length == 2
 * 0 <= xQueeni, yQueeni, xKing, yKing < 8
 * All the given positions are unique.
 * */

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens, vector<int> &king) {
        // 1 : 上, 2 : 下, 3 : 左, 4 : 右, 5 : 左上, 6 : 左下, 7 : 右上, 8 : 右下
        map<int, vector<vector<int>>> allowQueen;
        for (auto queen: queens) {
            int flag = canAttacktheKing(king, queen);
            if (flag) {
                allowQueen[flag].emplace_back(queen);
            }
        }
        vector<vector<int>> ans;
        for (auto queens: allowQueen) {
            vector<int> temp = {1024, 1024};
            for (auto queen: queens.second) {
                if (abs(queen[0] - king[0]) + abs(queen[1] - king[1]) <
                    abs(temp[0] - king[0]) + abs(temp[1] - king[1])) {
                    temp = queen;
                }
            }
            if (temp != vector<int>{1024, 1024}) {
                ans.emplace_back(temp);
            }
        }
        return ans;
    }

    int canAttacktheKing(vector<int> &king, vector<int> &queen) {
        if (queen[1] == king[1]) {
            if (queen[0] < king[0]) {
                return 1;
            } else {
                return 2;
            }
        }
        if (queen[0] == king[0]) {
            if (queen[1] < king[1]) {
                return 3;
            } else {
                return 4;
            }
        }
        if (abs(queen[0] - king[0]) == abs(queen[1] - king[1])) {
            if (queen[0] < king[0]) {
                if (queen[1] < king[1]) {
                    return 5;
                } else {
                    return 7;
                }
            } else {
                if (queen[1] < king[1]) {
                    return 6;
                } else {
                    return 8;
                }
            }
        }
        return 0;
    }
};

// 时间4 ms，击败86.93%
// 内存11.8 MB，击败5.11%