class Solution {
public:
    int k=0;
    int a=0;
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            unordered_set<char>set1;
            unordered_set<char>set2;
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'&&set1.find(board[i][j])!=set1.end()) return false;
                if(board[j][i]!='.'&&set2.find(board[j][i])!=set2.end()) return false;
                set1.insert(board[i][j]);
                set2.insert(board[j][i]);
            }
        }
        
        for(int row=0;row<9;row=row+3){
            for(int col=0;col<9;col=col+3){
                unordered_set<char>set3;
                for(int i=row;i<row+3;i++){
                    for(int j=col;j<col+3;j++){
                        if(board[i][j]=='.') continue;
                        if(set3.find(board[i][j])!=set3.end()) return false;
                        set3.insert(board[i][j]);
                    }
                }
            }
        }
        return true;
        
    }
};
