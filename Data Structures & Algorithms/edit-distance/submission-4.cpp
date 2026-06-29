class Solution {
public:
    vector<vector<int>> dp;

    int dfs(string &word1, string &word2, int i, int j) {
        if(i == word1.length())
            return word2.length() - j;
        
        if(j == word2.length())
            return word1.length() - i;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(word1[i] == word2[j])
            return dp[i][j] = dfs(word1, word2, i+1, j+1);

        int replace = dfs(word1, word2, i+1, j+1);
        int del = dfs(word1, word2, i+1, j);
        int insert = dfs(word1, word2, i, j+1);

        return dp[i][j] = 1 + min({replace, del, insert});
    }

    int minDistance(string word1, string word2) {
        dp.assign(word1.length()+1,
                  vector<int>(word2.length()+1, -1));

        return dfs(word1, word2, 0, 0);
    }
};