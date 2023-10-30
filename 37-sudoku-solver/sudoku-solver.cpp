class Solution {
public:
    bool isValid(vector<vector<char>>& board ,int row, int col, char k){
        for(int i=0;i<=8;i++){//element already in same row
            if(board[row][i]==k)return false;
            if(board[i][col]==k)return false;
            if(board[3*(row/3) + i/3][3*(col/3) + i%3]==k)return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(char k='1';k<='9';k++){
                        if(isValid(board,i,j,k)){
                            board[i][j]=k;
                        if(solve(board))return true;
                        else board[i][j]='.';
                        }
                    }
                    return false;
                }

            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};