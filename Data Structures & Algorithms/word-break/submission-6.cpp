class Solution {
public:
    vector<int> dp;

    bool dfs(string& s, unordered_set<string>& sets, int i) {
        if(i == s.length()) return true;

        if(dp[i] != -1) return dp[i];

        string str = "";

        for(int j = i; j < s.length(); j++) {
            str += s[j];

            if(sets.find(str) != sets.end()) {
                if(dfs(s, sets, j + 1))
                    return dp[i] = true;
            }
        }

        return dp[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> sets(wordDict.begin(), wordDict.end());

        dp.resize(s.length(), -1);

        return dfs(s, sets, 0);
    }
};