// Problem: Construct Product Matrix
// Platform: LeetCode
// Language: C
// Topic: Arrays / Matrix / Prefix-Suffix
// Time Complexity: O(m × n)
// Space Complexity: O(m × n)

int** constructProductMatrix(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {


    int m = gridSize;
    int n = gridColSize[0];
    int size = m * n;
    int mod = 12345;

    int* arr = (int*)malloc(size * sizeof(int));
    int idx = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            arr[idx++] = grid[i][j];
        }
    }

    long long* prefix = (long long*)malloc(size * sizeof(long long));
    prefix[0] = 1;

    for(int i = 1; i < size; i++) {
        prefix[i] = (prefix[i-1] * 1LL * arr[i-1]) % mod;
    }

    long long* suffix = (long long*)malloc(size * sizeof(long long));
    suffix[size-1] = 1;

    for(int i = size-2; i >= 0; i--) {
        suffix[i] = (suffix[i+1] * 1LL * arr[i+1]) % mod;
    }


    int* result1D = (int*)malloc(size * sizeof(int));

    for(int i = 0; i < size; i++) {
        result1D[i] = (int)((prefix[i] * suffix[i]) % mod);
    }

    int** result = (int**)malloc(m * sizeof(int*));
    *returnColumnSizes = (int*)malloc(m * sizeof(int));

    idx = 0;
    for(int i = 0; i < m; i++) {
        result[i] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;

        for(int j = 0; j < n; j++) {
            result[i][j] = result1D[idx++];
        }
    }

    *returnSize = m;
    return result;
}
