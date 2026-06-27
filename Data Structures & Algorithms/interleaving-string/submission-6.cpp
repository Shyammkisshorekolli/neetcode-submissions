#include <cstring>
class Solution {
public:
    int dp[101][101];

    bool dfs(string &s1, string &s2, string &s3,
             int i, int j) {

        if (i == s1.size() && j == s2.size())
            return true;

        if (dp[i][j] != -1)
            return dp[i][j];

        int k = i + j;
        bool ans = false;

        if (i < s1.size() && s1[i] == s3[k])
            ans |= dfs(s1, s2, s3, i + 1, j);

        if (j < s2.size() && s2[j] == s3[k])
            ans |= dfs(s1, s2, s3, i, j + 1);

        return dp[i][j] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {

        if (s1.size() + s2.size() != s3.size())
            return false;

        memset(dp, -1, sizeof(dp));

        return dfs(s1, s2, s3, 0, 0);
    }
};