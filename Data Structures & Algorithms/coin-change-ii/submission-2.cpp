class Solution {
public:
    vector<vector<int>>dp;
    int dfs(int amount,vector<int>&coins,int i){
        if(i>=coins.size()) return 0;
        if(amount<0) return 0;
        if(amount==0) return dp[i][amount]=1;
        if(dp[i][amount]!=-1) return dp[i][amount];
        dp[i][amount]=0;
        dp[i][amount]=dp[i][amount]+dfs(amount-coins[i],coins,i);
        while(i+1<coins.size()&&coins[i+1]==coins[i]){
            i++;
        }
        dp[i][amount]=dp[i][amount]+dfs(amount,coins,i+1);
        return dp[i][amount];
    }
    int change(int amount, vector<int>& coins) {
        dp.assign(coins.size(),vector<int>(amount+1,-1));
        sort(coins.begin(),coins.end());
        dfs(amount,coins,0);
        return dp[0][amount];
    }
};
