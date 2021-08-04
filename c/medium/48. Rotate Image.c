/*
* 48. Rotate Image
* You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
* You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. 
* DO NOT allocate another 2D matrix and do the rotation.
* 
* Example 1:
* Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
* Output: [[7,4,1],[8,5,2],[9,6,3]]
*
* Example 2:
* Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
* Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
*
* Example 3:
* Input: matrix = [[1]]
* Output: [[1]]
*
* Example 4:
* Input: matrix = [[1,2],[3,4]]
* Output: [[3,1],[4,2]]
*  
* Constraints:
* matrix.length == n
* matrix[i].length == n
* 1 <= n <= 20
* -1000 <= matrix[i][j] <= 1000
*/

// 新开了一个二维数组辅助旋转（不合要求）
void rotate(int** matrix, int matrixSize, int* matrixColSize) 
{
    int** tempMat = (int**)malloc(sizeof(int*) * matrixSize);
    int i, j;
    for (i = 0; i < matrixSize; i++)
        tempMat[i] = (int*)malloc(sizeof(int) * matrixSize);
    for (i = 0; i < matrixSize; i++)
        for (j = 0; j < matrixSize; j++)
            tempMat[i][j] = matrix[i][j];
    for (i = 0; i < matrixSize; i++)
    {
        for (j = 0; j < matrixSize; j++)
        {
            matrix[j][matrixSize - 1 - i] = tempMat[i][j];
        }
    }
    for (i = 0; i < matrixSize; i++)
        free(tempMat[i]);
    free(tempMat);
}
/*
* 执行结果：通过
* 执行用时：0 ms, 在所有 C 提交中击败了100.00%的用户
* 内存消耗：6.1 MB, 在所有 C 提交中击败了58.06%的用户
*/

// 通过翻转解决（满足要求）
void rotate(int** matrix, int matrixSize, int* matrixColSize) 
{
    //先转置矩阵
    for (int i = 0; i < matrixSize; ++i)
        for (int j = 0; j < i; ++j) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    //再镜像对称
    int left = 0;
    int right = matrixSize - 1;
    while (left < right) {
        for (int i = 0; i < matrixSize; ++i) {
            int temp = matrix[i][left];
            matrix[i][left] = matrix[i][right];
            matrix[i][right] = temp;
        }
        left++;
        right--;
    }
}
/*
* 执行结果：通过
* 执行用时：0 ms, 在所有 C 提交中击败了100.00%的用户
* 内存消耗：6 MB, 在所有 C 提交中击败了92.18%的用户
*/

//原地旋转（未开任何空间，满足要求）
void rotate(int** matrix, int matrixSize, int* matrixColSize)
{
    for (int i = 0; i < matrixSize / 2; ++i)
    {
        for (int j = 0; j < (matrixSize + 1) / 2; ++j)
        {
            matrix[i][j] += matrix[matrixSize - j - 1][i] + 
                matrix[matrixSize - i - 1][matrixSize - j - 1] + matrix[j][matrixSize - i - 1];
            matrix[j][matrixSize - i - 1] = matrix[i][j] - 
                (matrix[matrixSize - j - 1][i] + matrix[matrixSize - i - 1][matrixSize - j - 1] + matrix[j][matrixSize - i - 1]);
            matrix[matrixSize - i - 1][matrixSize - j - 1] = matrix[i][j] - 
                (matrix[matrixSize - j - 1][i] + matrix[matrixSize - i - 1][matrixSize - j - 1] + matrix[j][matrixSize - i - 1]);
            matrix[matrixSize - j - 1][i] = matrix[i][j] - 
                (matrix[matrixSize - j - 1][i] + matrix[matrixSize - i - 1][matrixSize - j - 1] + matrix[j][matrixSize - i - 1]);
            matrix[i][j] -= matrix[matrixSize - j - 1][i] + 
                matrix[matrixSize - i - 1][matrixSize - j - 1] + matrix[j][matrixSize - i - 1];
        }
    }
}
/*
* 执行结果：通过
* 执行用时：0 ms, 在所有 C 提交中击败了100.00%的用户
* 内存消耗：6 MB, 在所有 C 提交中击败了92.18%的用户
*/