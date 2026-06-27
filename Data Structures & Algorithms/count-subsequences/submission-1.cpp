class Solution {
public:
    vector<vector<long long>> dp;

    long long dfs(string &s, string &t, int i, int j) {

        if (j == t.size())
            return 1;

        if (i == s.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        long long ans = dfs(s, t, i + 1, j);

        if (s[i] == t[j])
            ans += dfs(s, t, i + 1, j + 1);

        return dp[i][j] = ans;
    }

    int numDistinct(string s, string t) {

        dp.assign(s.size(), vector<long long>(t.size(), -1));

        return dfs(s, t, 0, 0);
    }
};