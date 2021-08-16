/*
* 1901. Find a Peak Element II
* A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.
* Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].
* You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.
* You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.
*
* Example 1:
* Input: mat = [[1,4],[3,2]]
* Output: [0,1]
* Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.
* Example 2:
* Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
* Output: [1,1]
* Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.
*
* Constraints:
* m == mat.length
* n == mat[i].length
* 1 <= m, n <= 500
* 1 <= mat[i][j] <= 10^5
* No two adjacent cells are equal.
*/

// 按题意（未优化）
void isTop(int** mat, int** mask, int i, int j, int n, int m)
{
    int count = 0;
    // 判断与上方的大小
    if (i == 0)
    {
        mask[i][j + 1] = -1;
        ++count;
    }
    else if (mat[i][j] > mat[i - 1][j])
    {
        mask[i][j + 1] = -1;
        ++count;
    }
    // 判断与左方的大小
    if (j == 0)
    {
        mask[i + 1][j] = -1;
        ++count;
    }
    else if (mat[i][j] > mat[i][j - 1])
    {
        mask[i + 1][j] = -1;
        ++count;
    }
    // 判断与下方的大小
    if (i == n - 1)
    {
        mask[i + 2][j + 1] = -1;
        ++count;
    }
    else if (mat[i][j] > mat[i + 1][j])
    {
        mask[i + 2][j + 1] = -1;
        ++count;
    }
    // 判断与右方的大小
    if (j == m - 1)
    {
        mask[i + 1][j + 2] = -1;
        ++count;
    }
    else if (mat[i][j] > mat[i][j + 1])
    {
        mask[i + 1][j + 2] = -1;
        ++count;
    }
    // 若比周围都大，则该mask置1
    if (count == 4)
        mask[i + 1][j + 1] = 1;
}

int* findPeakGrid(int** mat, int matSize, int* matColSize, int* returnSize)
{
    int i;
    int* ret = (int*)malloc(sizeof(int) * 2);
    int** mask = (int**)malloc(sizeof(int*) * (2 + matSize));
    i = 0;
    while (i < 2 + matSize)
    {
        mask[i] = (int*)malloc(sizeof(int) * (2 + *matColSize));
        memset(mask[i++], 0, sizeof(int) * (*matColSize + 2));
    }
    i = 0;
    while (i < matSize)
    {
        int j = 0;
        while (j < *matColSize)
        {
            if (mask[i + 1][j + 1] >= 0)
            {
                isTop(mat, mask, i, j, matSize, *matColSize);
                if (mask[i + 1][j + 1] == 1)
                {
                    *returnSize = 2;
                    ret[0] = i;
                    ret[1] = j;
                    return ret;
                }
            }
            ++j;
        }
        ++i;
    }
    return ret;
}
/*
* 执行结果：通过
* 执行用时：228 ms, 在所有 C 提交中击败了50.00%的用户
* 内存消耗：25.7 MB, 在所有 C 提交中击败了6.67%的用户
*/

// 二分法查找
int* findPeakGrid(int** mat, int matSize, int* matColSize, int* returnSize)
{
    *returnSize = 2;
    int* ret = (int*)malloc(sizeof(int) * 2);
    int i = 0;
    while (i < matSize)
    {
        // 先找出每行中最大值
        int max = mat[i][0], idx = 0, j = 0;
        while (j < *matColSize)
        {
            if (max < mat[i][j])
            {
                max = mat[i][j];
                idx = j;
            }
            ++j;
        }
        // 再对比每行中最大值的上下位大小
        if (i == 0)
        {
            if (mat[i][idx] > mat[i + 1][idx])
            {
                ret[0] = i;
                ret[1] = idx;
                return ret;
            }
        }
        else if (i == matSize - 1)
        {
            if (mat[i][idx] > mat[i - 1][idx])
            {
                ret[0] = i;
                ret[1] = idx;
                return ret;
            }
        }
        else
        {
            if (mat[i][idx] > mat[i - 1][idx] && mat[i][idx] > mat[i + 1][idx])
            {
                ret[0] = i;
                ret[1] = idx;
                return ret;
            }
        }
        ++i;
    }
    return ret;
}
/*
* 执行结果：通过
* 执行用时：216 ms, 在所有 C 提交中击败了86.67%的用户
* 内存消耗：19.8 MB, 在所有 C 提交中击败了96.67%的用户
*/