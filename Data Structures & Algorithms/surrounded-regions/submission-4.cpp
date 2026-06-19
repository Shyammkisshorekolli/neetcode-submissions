class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        queue<pair<int,int>>q;
        vector<vector<bool>>surr(n,vector<bool>(m,true));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0||i==n-1||j==0||j==m-1)&&board[i][j]=='O'){
                    q.push({i,j});
                    surr[i][j]=false;
                }
                else continue;
            }
        }
        vector<pair<int,int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            auto [i,j]= q.front();
            q.pop();
            for(auto &d:dir){
                int ni=i+d.first;
                int nj=j+d.second;
                if(ni<0||nj<0||ni>=n||nj>=m) continue;
                if(!surr[ni][nj]) continue;
                if(board[ni][nj]=='X') continue;
                surr[ni][nj]=false;
                q.push({ni,nj});
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!surr[i][j]) continue;
                else board[i][j]='X';
            }
        }
    }
};
