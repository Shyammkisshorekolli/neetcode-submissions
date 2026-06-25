class Solution {
public:
   vector<int>dp;
   int dfs(vector<int>&nums,int i){
    if(i==nums.size()-1){
        return dp[i]=1;;
    }
    if(dp[i]!=-1) return dp[i];
    for(int j=i+1;j<nums.size();j++){
        int length=1;
        if(nums[j]>nums[i]) length=length+dfs(nums,j);
        dp[i]=max(length,dp[i]);
    }
    return dp[i];
   }
    int lengthOfLIS(vector<int>& nums) {
        dp.resize(nums.size(),-1);
        for(int i=0;i<nums.size();i++){
            dfs(nums,i);
        }
        return *max_element(dp.begin(),dp.end());
    }
};
