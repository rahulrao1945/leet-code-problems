/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int rows = matrixSize;
    int cols = matrixColSize[0];

    int *result = (int *)malloc(rows * cols * sizeof(int));
    int index = 0;

    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;

    while (top <= bottom && left <= right) {

        // Traverse left to right
        for (int j = left; j <= right; j++)
            result[index++] = matrix[top][j];
        top++;

        // Traverse top to bottom
        for (int i = top; i <= bottom; i++)
            result[index++] = matrix[i][right];
        right--;

        // Traverse right to left
        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                result[index++] = matrix[bottom][j];
            bottom--;
        }

        // Traverse bottom to top
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                result[index++] = matrix[i][left];
            left++;
        }
    }

    *returnSize = rows * cols;
    return result;
}