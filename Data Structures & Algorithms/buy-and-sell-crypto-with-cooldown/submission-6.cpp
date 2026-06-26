class Solution {
public:
    vector<vector<int>> dp;

    int dfs(vector<int>& prices, int i, bool buy) {
        if (i >= prices.size())
            return 0;

        if (dp[i][buy] != -1)
            return dp[i][buy];

        if (buy) {
            int take = -prices[i] + dfs(prices, i + 1, false);
            int skip = dfs(prices, i + 1, true);
            return dp[i][buy] = max(take, skip);
        } else {
            int sell = prices[i] + dfs(prices, i + 2, true);
            int hold = dfs(prices, i + 1, false);
            return dp[i][buy] = max(sell, hold);
        }
    }

    int maxProfit(vector<int>& prices) {
        dp.assign(prices.size(), vector<int>(2, -1));
        return dfs(prices, 0, true);
    }
};