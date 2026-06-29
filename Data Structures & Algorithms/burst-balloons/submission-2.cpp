class Solution {
public:
    vector<vector<int>> dp;

    int dfs(vector<int>& nums, int left, int right) {
        if (left > right)
            return 0;

        if (dp[left][right] != -1)
            return dp[left][right];

        int ans = 0;

        for (int k = left; k <= right; k++) {
            int coins = nums[left - 1] * nums[k] * nums[right + 1];

            coins += dfs(nums, left, k - 1);
            coins += dfs(nums, k + 1, right);

            ans = max(ans, coins);
        }

        return dp[left][right] = ans;
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();

        dp.assign(n, vector<int>(n-1, -1));

        return dfs(nums, 1, n - 2);
    }
};