class Solution {
public:
    bool pacific=false;
    bool atlantic=false;

    void dfs(vector<vector<int>>& heights,int i,int j,
             vector<vector<bool>>& visited){

        int n=heights.size();
        int m=heights[0].size();

        if(pacific && atlantic) return;

        visited[i][j]=true;

        if(i==0 || j==0) pacific=true;

        if(i==n-1 || j==m-1) atlantic=true;

        vector<vector<int>> dir={{0,1},{0,-1},{-1,0},{1,0}};

        for(auto &d : dir){
            int ni=i+d[0];
            int nj=j+d[1];

            if(ni<0 || nj<0 || ni>=n || nj>=m) continue;

            if(visited[ni][nj]) continue;

            if(heights[ni][nj] > heights[i][j]) continue;

            dfs(heights,ni,nj,visited);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int n=heights.size();
        int m=heights[0].size();

        vector<vector<int>> ans;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                pacific=false;
                atlantic=false;

                vector<vector<bool>> visited(
                    n, vector<bool>(m,false)
                );

                dfs(heights,i,j,visited);

                if(pacific && atlantic){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};