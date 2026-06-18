class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()) return;
        if(grid[i][j]=='0') return;
        grid[i][j]='0';
        vector<vector<int>>dirct={{0,1},{0,-1},{-1,0},{1,0}};
        for(auto &dir:dirct){
            int x=i+dir[0];
            int y=j+dir[1];
            dfs(grid,x,y);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};
