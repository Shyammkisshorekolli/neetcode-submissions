class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh=0;

        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({i,j});
                }
                if(grid[i][j]==1) fresh++;
            }
        }

        vector<vector<int>> dir = {
            {0,1}, {0,-1}, {1,0}, {-1,0}
        };
        int time=0;
        bool found=false;
        int l=q.size();
        while(!q.empty()&&fresh){
            auto [i,j]=q.front();
            q.pop();
            for(auto &d:dir){
                int ni = i+d[0];
                int nj = j+d[1];

                if(ni < 0 || nj < 0 || ni >= n || nj >= m)
                    continue;

                if(grid[ni][nj] != 1)
                    continue;

                grid[ni][nj] = 2;
                fresh--;
                found=true;
                q.push({ni,nj});
            }
            l--;
            if(l==0||fresh==0){
                time++;
                l=q.size();
            }
        }
        if(fresh==0) return time;
        else return -1;
    }
};
