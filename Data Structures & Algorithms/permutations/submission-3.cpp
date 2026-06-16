class Solution {
public:
    void dfs(vector<int>& nums,
             vector<bool>& used,
             vector<int>& ans,
             vector<vector<int>>& final) {

        if (ans.size() == nums.size()) {
            final.push_back(ans);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;

            ans.push_back(nums[i]);
            used[i] = true;

            dfs(nums, used, ans, final);

            used[i] = false;
            ans.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        vector<int> ans;
        vector<vector<int>> final;

        dfs(nums, used, ans, final);

        return final;
    }
};