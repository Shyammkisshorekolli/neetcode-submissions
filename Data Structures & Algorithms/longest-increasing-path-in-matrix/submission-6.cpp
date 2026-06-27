class Solution {
public:
    vector<vector<int>>dp;
    int dfs(vector<vector<int>>& matrix,int i,int j){
        if(dp[i][j]!=-1) return dp[i][j];
        dp[i][j]=0;
        vector<vector<int>>dir={{0,1},{0,-1},{-1,0},{1,0}};
        for(auto &d:dir){
            int ni=i+d[0];
            int nj=j+d[1];
            if(ni<0||nj<0||ni>=matrix.size()||nj>=matrix[0].size()) continue;
            if(matrix[ni][nj]<=matrix[i][j]) continue;
            dp[i][j]=max(dp[i][j],1+dfs(matrix,ni,nj));
        }
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        dp.assign(matrix.size(),vector<int>(matrix[0].size(),-1));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(dp[i][j]!=-1) continue;
                dfs(matrix,i,j);
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[0].size();j++){
                ans=max(ans,dp[i][j]);
            }
        }
        return ans+1;
    }
};
