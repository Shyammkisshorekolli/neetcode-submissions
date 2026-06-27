class Solution {
public:
    unordered_map<string, bool> dp;

    bool dfs(string &s1, string &s2, string &s3,
             int i, int j, int k,
             int one, int two) {

        if (abs(one - two) > 1)
            return false;

        if (i == s3.size()) {
            return (j == s1.size() &&
                    k == s2.size() &&
                    abs(one - two) <= 1);
        }

        string key = to_string(j) + "#" +
                     to_string(k) + "#" +
                     to_string(one) + "#" +
                     to_string(two);

        if (dp.count(key))
            return dp[key];

        bool ans = false;

        // Take substring from s1
        if (j < s1.size() && s3[i] == s1[j]) {

            int x = i;
            int y = j;

            while (x < s3.size() &&
                   y < s1.size() &&
                   s3[x] == s1[y]) {

                ans |= dfs(s1, s2, s3,
                           x + 1, y + 1, k,
                           one + 1, two);

                if (ans)
                    return dp[key] = true;

                x++;
                y++;
            }
        }

        // Take substring from s2
        if (k < s2.size() && s3[i] == s2[k]) {

            int x = i;
            int z = k;

            while (x < s3.size() &&
                   z < s2.size() &&
                   s3[x] == s2[z]) {

                ans |= dfs(s1, s2, s3,
                           x + 1, j, z + 1,
                           one, two + 1);

                if (ans)
                    return dp[key] = true;

                x++;
                z++;
            }
        }

        return dp[key] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {

        if (s1.size() + s2.size() != s3.size())
            return false;

        dp.clear();

        return dfs(s1, s2, s3, 0, 0, 0, 0, 0);
    }
};