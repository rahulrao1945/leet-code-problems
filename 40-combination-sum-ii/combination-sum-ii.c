#include <stdlib.h>

void backtrack(int* candidates, int candidatesSize, int target, int start,
               int* path, int pathSize,
               int*** result, int* returnSize,
               int** returnColumnSizes) {

    if (target == 0) {
        (*result)[*returnSize] = (int*)malloc(pathSize * sizeof(int));
        for (int i = 0; i < pathSize; i++)
            (*result)[*returnSize][i] = path[i];

        (*returnColumnSizes)[*returnSize] = pathSize;
        (*returnSize)++;
        return;
    }

    for (int i = start; i < candidatesSize; i++) {
        if (i > start && candidates[i] == candidates[i - 1])
            continue;

        if (candidates[i] > target)
            break;

        path[pathSize] = candidates[i];
        backtrack(candidates, candidatesSize, target - candidates[i], i + 1,
                  path, pathSize + 1,
                  result, returnSize, returnColumnSizes);
    }
}

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** combinationSum2(int* candidates, int candidatesSize, int target,
                      int* returnSize, int** returnColumnSizes) {

    qsort(candidates, candidatesSize, sizeof(int), cmp);

    int** result = (int**)malloc(1000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(1000 * sizeof(int));
    int* path = (int*)malloc(candidatesSize * sizeof(int));

    *returnSize = 0;

    backtrack(candidates, candidatesSize, target, 0,
              path, 0,
              &result, returnSize, returnColumnSizes);

    free(path);
    return result;
}