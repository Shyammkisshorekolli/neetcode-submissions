class Solution {
public:
    vector<int>dp;
    int dfs(vector<int>&nums,int i){
        if(i==nums.size()-1) return 1;
        if(dp[i]!=-1) return dp[i];
        dp[i]=0;
        for(int j=1;j<=nums[i];j++){
            if(dfs(nums,i+j)) return dp[i]=1;
        }
        return dp[i];
    }
    bool canJump(vector<int>& nums) {
        dp.resize(nums.size(),-1);
        if(nums.size()==1) return  true;
        dfs(nums,0);
        if(dp[0]==1) return true;
        else return false;
   }
};
