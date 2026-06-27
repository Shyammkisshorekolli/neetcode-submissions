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

        bool ans = false;
        int k = i + j;

        if (i < s1.size() && s3[k] == s1[i]) {

            int x = k;
            int y = i;

            while (x < s3.size() &&
                   y < s1.size() &&
                   s3[x] == s1[y]) {

                ans |= dfs(s1, s2, s3,
                           y + 1, j);

                if (ans)
                    break;

                x++;
                y++;
            }
        }

        if (!ans && j < s2.size() && s3[k] == s2[j]) {

            int x = k;
            int z = j;

            while (x < s3.size() &&
                   z < s2.size() &&
                   s3[x] == s2[z]) {

                ans |= dfs(s1, s2, s3,
                           i, z + 1);

                if (ans)
                    break;

                x++;
                z++;
            }
        }

        return dp[i][j] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {

        if (s1.size() + s2.size() != s3.size())
            return false;

        memset(dp, -1, sizeof(dp));

        return dfs(s1, s2, s3, 0, 0);
    }
};