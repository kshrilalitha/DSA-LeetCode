// Problem: Maximum Non-Negative Product in a Matrix
// Platform: LeetCode
// Topic: Matrix, Dynamic Programming
// Time Complexity: O(m * n)
// Space Complexity: O(m * n)

int maxProductPath(int** grid, int m, int* gridColSize) {

    int n = gridColSize[0];
    long maxDP[m][n];
    long minDP[m][n];

    maxDP[0][0] = minDP[0][0] = grid[0][0];

    
    for(int j = 1; j < n; j++) {
        maxDP[0][j] = minDP[0][j] = maxDP[0][j-1] * grid[0][j];
    }

    
    for(int i = 1; i < m; i++) {
        maxDP[i][0] = minDP[i][0] = maxDP[i-1][0] * grid[i][0];
    }

    
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {

            long a = maxDP[i-1][j] * grid[i][j];
            long b = minDP[i-1][j] * grid[i][j];
            long c = maxDP[i][j-1] * grid[i][j];
            long d = minDP[i][j-1] * grid[i][j];

            long maxVal = a;
            if(b > maxVal) maxVal = b;
            if(c > maxVal) maxVal = c;
            if(d > maxVal) maxVal = d;

            long minVal = a;
            if(b < minVal) minVal = b;
            if(c < minVal) minVal = c;
            if(d < minVal) minVal = d;

            maxDP[i][j] = maxVal;
            minDP[i][j] = minVal;
        }
    }

    long result = maxDP[m-1][n-1];

    if(result < 0) return -1;

    return result % 1000000007;    
}
