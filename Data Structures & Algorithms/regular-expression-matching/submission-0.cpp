class Solution {
public:
    vector<vector<int>> dp;

    bool dfs(string &s, string &p, int i, int j) {
        if (j == p.size())
            return i == s.size();

        if (dp[i][j] != -1)
            return dp[i][j];

        bool firstMatch = (i < s.size()) &&
                          (s[i] == p[j] || p[j] == '.');

        if (j + 1 < p.size() && p[j + 1] == '*') {
            return dp[i][j] =
                dfs(s, p, i, j + 2) ||               // use 0 occurrence
                (firstMatch && dfs(s, p, i + 1, j)); // use 1 or more
        }

        return dp[i][j] =
            firstMatch && dfs(s, p, i + 1, j + 1);
    }

    bool isMatch(string s, string p) {
        dp.assign(s.size()+1, vector<int>(p.size() , -1));
        return dfs(s, p, 0, 0);
    }
};