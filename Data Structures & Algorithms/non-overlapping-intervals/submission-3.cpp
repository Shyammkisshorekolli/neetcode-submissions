class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int dfs(vector<vector<int>>& intervals, int i, int j) {
        if (i >= n - 1 || j >= n)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        // No overlap
        if (intervals[i][1] <= intervals[j][0]) {
            return dp[i][j] = dfs(intervals, j, j + 1);
        }

        // Overlap
        int removeJ = 1 + dfs(intervals, i, j + 1);
        int removeI = 1 + dfs(intervals, j, j + 1);
        int removeBoth = 2 + dfs(intervals, j + 1, j + 2);

        return dp[i][j] = min({removeJ, removeI, removeBoth});
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        n = intervals.size();
        dp.assign(n + 1, vector<int>(n + 1, -1));

        return dfs(intervals, 0, 1);
    }
};