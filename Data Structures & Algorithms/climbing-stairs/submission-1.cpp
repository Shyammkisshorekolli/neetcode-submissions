class Solution {
public:
    vector<int> dp;

    int recursive(int n){
        if(n <= 1) return 1;

        if(dp[n] != -1) return dp[n];

        return dp[n] = recursive(n-1) + recursive(n-2);
    }

    int climbStairs(int n) {
        dp.resize(n+1, -1);
        return recursive(n);
    }
};