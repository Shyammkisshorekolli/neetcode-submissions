class Solution {
public:
    vector<int>dp;
    int recursive(vector<int>&nums,int i){
        if(i>=nums.size()) return 0;
        if(i>=nums.size()-2) return dp[i]=nums[i];
        if(dp[i]!=-1) return dp[i];
        return dp[i]=nums[i]+max(recursive(nums,i+2),recursive(nums,i+3));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n,-1);
        recursive(nums,0);
        recursive(nums,1);
        if(n==1) return dp[0];
        else return max(dp[0],dp[1]);
    }
};
