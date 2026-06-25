class Solution {
public:
    vector<vector<int>> dp;
    bool found=false;

    bool dfs(vector<int>& nums, int i, int target) {
        if(found) return true;
        if (target == 0){
            found=true;
            return true;
        }
        if (i == nums.size() || target < 0)
            return false;

        if (dp[i][target] != -1)
            return dp[i][target];

        bool take = dfs(nums, i + 1, target - nums[i]);
        bool notTake = dfs(nums, i + 1, target);

        return dp[i][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;

        for (int x : nums)
            sum += x;

        if (sum % 2)
            return false;

        int target = sum / 2;

        dp.assign(nums.size(), vector<int>(target + 1, -1));

        return dfs(nums, 0, target);
    }
};