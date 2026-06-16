class Solution {
public:
    void dfs(vector<int>&nums,unordered_set<int>sets,vector<int>&ans,vector<vector<int>>&final){
        if(ans.size()==nums.size()){
            final.push_back(ans);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(sets.find(nums[i])!=sets.end()) continue;
            ans.push_back(nums[i]);
            sets.insert(nums[i]);
            dfs(nums,sets,ans,final);
            sets.erase(nums[i]);
            ans.pop_back();
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int>sets;
        vector<int>ans;
        vector<vector<int>>final;
        dfs(nums,sets,ans,final);
        return final;
    }
};
