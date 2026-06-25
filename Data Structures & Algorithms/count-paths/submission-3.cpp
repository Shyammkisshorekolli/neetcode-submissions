class Solution {
public:
    vector<vector<int>> dp;

    int dfs(int i, int j, int m, int n) {
        if (i == m - 1 && j == n - 1)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        dp[i][j] = 0;

        vector<vector<int>> dir = {{1,0},{0,1}};

        for (auto &d : dir) {
            int ni = i + d[0];
            int nj = j + d[1];

            if (ni >= m || nj >= n)
                continue;

            dp[i][j] += dfs(ni, nj, m, n);
        }

        return dp[i][j];
    }

    int uniquePaths(int m, int n) {
        dp.assign(m, vector<int>(n, -1));
        return dfs(0, 0, m, n);
    }
};