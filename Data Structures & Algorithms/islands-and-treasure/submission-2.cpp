class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;

        // Push all gates
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    q.push({i,j});
                }
            }
        }

        vector<vector<int>> dir = {
            {0,1}, {0,-1}, {1,0}, {-1,0}
        };

        while(!q.empty()) {
            auto [i,j] = q.front();
            q.pop();

            for(auto &d : dir) {
                int ni = i + d[0];
                int nj = j + d[1];

                if(ni < 0 || nj < 0 || ni >= n || nj >= m)
                    continue;

                if(grid[ni][nj] != INT_MAX)
                    continue;

                grid[ni][nj] = grid[i][j] + 1;
                q.push({ni,nj});
            }
        }
    }
};