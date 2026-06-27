class Solution {
public:
    vector<vector<int>> dp;
    int m, n;

    const int dir[4][2] = {
        {0, 1},
        {0, -1},
        {-1, 0},
        {1, 0}
    };

    int dfs(vector<vector<int>>& matrix, int i, int j) {
        if (dp[i][j] != -1)
            return dp[i][j];

        dp[i][j] = 0;

        for (int k = 0; k < 4; k++) {
            int ni = i + dir[k][0];
            int nj = j + dir[k][1];

            if (ni < 0 || nj < 0 || ni >= m || nj >= n)
                continue;

            if (matrix[ni][nj] <= matrix[i][j])
                continue;

            dp[i][j] = max(dp[i][j], 1 + dfs(matrix, ni, nj));
        }

        return dp[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        dp.assign(m, vector<int>(n, -1));

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dfs(matrix, i, j));
            }
        }

        return ans + 1;
    }
};