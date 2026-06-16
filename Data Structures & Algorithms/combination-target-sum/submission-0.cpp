class Solution {
public:
    void dfs(vector<int>& nums, int target, int i, int sum,
             vector<int>& ans, vector<vector<int>>& final) {

        if (sum == target) {
            final.push_back(ans);
            return;
        }

        if (i >= nums.size() || sum > target)
            return;

        // take nums[i]
        ans.push_back(nums[i]);
        dfs(nums, target, i, sum + nums[i], ans, final);

        // backtrack
        ans.pop_back();

        // don't take nums[i]
        dfs(nums, target, i + 1, sum, ans, final);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> ans;
        vector<vector<int>> final;
        dfs(nums, target, 0, 0, ans, final);
        return final;
    }
};