class Solution {
public:
    vector<vector<int>>dp;
    int dfs(vector<int>& nums, int target,int i,int sum,int total){
        if(i==nums.size()){
            if(target==sum) return 1;
            else return 0;
        }
        if(dp[i][sum+total]!=-1) return dp[i][sum+total];
        int add=sum+nums[i];
        int subtract=sum-nums[i];
        int x=dfs(nums,target,i+1,add,total);
        int y=dfs(nums,target,i+1,subtract,total);
        dp[i][sum+total]=x+y;
        return dp[i][sum+total];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int total=0;
        for(auto &x:nums) total=total+x;
        dp.assign(nums.size(),vector<int>(2*total+1,-1));
        dfs(nums,target,0,0,total);
        return dp[0][total];
    }
};
