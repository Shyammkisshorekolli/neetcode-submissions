class Solution {
public:
    void dfs(vector<int>& candidates, int target, int i, int sum,
             vector<int>& ans, vector<vector<int>>& final) {

        if (sum == target) {
            final.push_back(ans);
            return;
        }

        if (i >= candidates.size() || sum > target)
            return;

        ans.push_back(candidates[i]);
        dfs(candidates, target, i + 1, sum + candidates[i], ans, final);

        ans.pop_back();
        while(i+1<candidates.size()&&candidates[i]==candidates[i+1]){
            i++;
        }
        dfs(candidates, target, i + 1, sum, ans, final);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ans;
        vector<vector<int>> final;
        sort(candidates.begin(),candidates.end());
        dfs(candidates, target, 0, 0, ans, final);

        return final;
    }
};