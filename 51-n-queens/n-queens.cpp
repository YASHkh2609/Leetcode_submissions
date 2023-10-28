class Solution {
public:
    bool isSafe(int row, int col, vector<string>&board, int n){
        int duprow=row;
        int dupcol=col;

        while(row>=0 && col>=0){
            if(board[row][col]=='Q')
                return false;
            row--;
            col--;
        }

        row=duprow;
        col=dupcol;

        while(col>=0){
            if(board[row][col]=='Q')
                return false;
            col--;
        }

        col=dupcol;
        row=duprow;
        while(row<n && col>=0){
            if(board[row][col]=='Q')
                return false;
            row++;
            col--;
        }

        return true;
    }
    void Solve(int col,vector<string>&board, vector<vector<string>>&ans, int n,vector<int>&leftrow,vector<int>&upperdiagonal, vector<int>&lowerdiagonal ){
        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++){
            if(leftrow[row]==0 && upperdiagonal[(n-1) +(col-row)]==0 && lowerdiagonal[row+col]==0){
                board[row][col]='Q';
                leftrow[row]=1;
                upperdiagonal[(n-1) +(col-row)]=1;
                lowerdiagonal[row+col]=1;
                Solve(col + 1,board, ans,n,leftrow,upperdiagonal,lowerdiagonal);
                board[row][col]='.';
                leftrow[row]=0;
                upperdiagonal[(n-1) +(col-row)]=0;
                lowerdiagonal[row+col]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        //Solve(0,board,ans,n);
        vector<int>leftrow(n,0),upperdiagonal(2*n-1,0),lowerdiagonal(2*n-1,0);
        Solve(0,board,ans,n,leftrow,upperdiagonal,lowerdiagonal);
        return ans;
    }
};