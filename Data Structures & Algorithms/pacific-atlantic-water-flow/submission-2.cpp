class Solution {
public:

    void dfs(vector<vector<int>>& heights,
             vector<vector<bool>>& visited,
             int i,int j){

        int n=heights.size();
        int m=heights[0].size();

        visited[i][j]=true;

        vector<pair<int,int>> dir={{0,1},{0,-1},{1,0},{-1,0}};

        for(auto &d : dir){
            int ni=i+d.first;
            int nj=j+d.second;

            if(ni<0 || nj<0 || ni>=n || nj>=m)
                continue;

            if(visited[ni][nj])
                continue;

            // reverse flow
            if(heights[ni][nj] < heights[i][j])
                continue;

            dfs(heights,visited,ni,nj);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int n=heights.size();
        int m=heights[0].size();

        vector<vector<bool>> pacific(n,vector<bool>(m,false));
        vector<vector<bool>> atlantic(n,vector<bool>(m,false));

        // Pacific
        for(int i=0;i<n;i++)
            dfs(heights,pacific,i,0);

        for(int j=0;j<m;j++)
            dfs(heights,pacific,0,j);

        // Atlantic
        for(int i=0;i<n;i++)
            dfs(heights,atlantic,i,m-1);

        for(int j=0;j<m;j++)
            dfs(heights,atlantic,n-1,j);

        vector<vector<int>> ans;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i,j});
            }
        }

        return ans;
    }
};