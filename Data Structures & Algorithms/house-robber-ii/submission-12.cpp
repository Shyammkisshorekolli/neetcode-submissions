class Solution {
public:
    vector<int> dp;

    int recursive(vector<int>& nums, int i, int end) {
        if(i > end) return 0;
        if(i >= end-1) return dp[i] = nums[i];

        if(dp[i] != -1) return dp[i];

        return dp[i] = nums[i] +
               max(recursive(nums,i+2,end),
                   recursive(nums,i+3,end));
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        dp.assign(n,-1);
        recursive(nums,0,n-2);
        int case1 = dp[0];;

        dp.assign(n,-1);
        recursive(nums,1,n-1);
        recursive(nums,2,n-1);
        int case2 = max(dp[1],dp[2]);

        return max(case1,case2);
    }
};