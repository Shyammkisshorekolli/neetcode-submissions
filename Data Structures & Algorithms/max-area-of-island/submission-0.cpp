class Solution {
public:
    int dfs(vector<vector<int>>& grid,int i,int j,int &count){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()) return count;
        if(grid[i][j]==0) return count;
        grid[i][j]=0;
        count++;
        vector<vector<int>>dirct={{0,1},{0,-1},{-1,0},{1,0}};
        for(auto &dir:dirct){
            int x=i+dir[0];
            int y=j+dir[1];
            dfs(grid,x,y,count);
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int max_island=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int count=0;
                    int x=dfs(grid,i,j,count);
                    max_island=max(max_island,x);
                }
            }
        }
        return max_island;
    }
};
