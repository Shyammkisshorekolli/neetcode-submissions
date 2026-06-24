class Solution {
public:
    vector<int> dp;

    int recursive(string &s, int i) {
        if (i == s.length()) return 1;

        if (s[i] == '0') return 0;

        if (dp[i] != -1) return dp[i];

        int ans = recursive(s, i + 1);

        if (i + 1 < s.length()) {
            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');

            if (num >= 10 && num <= 26) {
                ans += recursive(s, i + 2);
            }
        }

        return dp[i] = ans;
    }

    int numDecodings(string s) {
        dp.resize(s.length(), -1);
        return recursive(s, 0);
    }
};