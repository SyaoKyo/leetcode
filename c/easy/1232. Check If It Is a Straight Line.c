/*
* 1232. Check If It Is a Straight Line
* You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. 
* Check if these points make a straight line in the XY plane.
* Example 1:
* Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
* Output: true
* Example 2:
* Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
* Output: false
*
* Constraints:
* 2 <= coordinates.length <= 1000
* coordinates[i].length == 2
* -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
* coordinates contains no duplicate point.
*/
const int MAX = ~(1 << 31);
bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize)
{
    double K;
    int i;
    if ((coordinates[1][0] - coordinates[0][0]))
        K = 1.0 * (coordinates[1][1] - coordinates[0][1]) / (coordinates[1][0] - coordinates[0][0]);
    else
        K = MAX;
    i = 2;
    while (i < coordinatesSize)
    {
        if ((coordinates[i][0] - coordinates[i - 1][0]))
        {
            if (1.0 * (coordinates[i][1] - coordinates[i - 1][1]) / (coordinates[i][0] - coordinates[i - 1][0]) != K)
                return false;
        }
        else
            if (K != MAX)
                return false;
        ++i;
    }
    return true;
}
/*
* 执行结果：通过
* 执行用时：8 ms, 在所有 C 提交中击败了97.44%的用户
* 内存消耗：6.3 MB, 在所有 C 提交中击败了74.36%的用户
*/