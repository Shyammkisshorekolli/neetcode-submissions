class Solution {
public:
    bool found=false;
    void dfs(vector<vector<char>>& board,string &s,string word,int i,int j,vector<vector<bool>>&used){
        if(i<0||j<0||i>=board.size()||j>=board[0].size()) return;
        if(used[i][j]||found) return;
        if(s.length()>=word.length()){
            if(s==word){
                found=true;
                return;
            }
            else return;
        }
        s += board[i][j];
       if(s == word){
            found = true;
            s.pop_back();
            return;
        }
        if(s.length() >= word.length()){
            s.pop_back();
            return;
        }
        used[i][j]=true;
        dfs(board,s,word,i+1,j,used);
        dfs(board,s,word,i-1,j,used);
        dfs(board,s,word,i,j+1,used);
        dfs(board,s,word,i,j-1,used);
        used[i][j]=false;
        s.pop_back();
    }
    bool exist(vector<vector<char>>& board, string word) {
        string s="";
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>>used(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dfs(board,s,word,i,j,used);
                if(found) return true;
            }
        }
        return false;
    }
};
