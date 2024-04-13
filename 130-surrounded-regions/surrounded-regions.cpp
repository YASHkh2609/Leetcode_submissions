class Solution {
public:
    void bfs(int row, int col,vector<vector<char>>& board, vector<vector<int>>&vis ){
        queue<pair<int,int>>q;
        q.push({row, col});
        vis[row][col]=1;
        int m=board.size();
        int n=board[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,-1,0,1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nrow=r+delrow[i];
                int ncol=c+delcol[i];

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && board[nrow][ncol]=='O' && !vis[nrow][ncol]){
                    q.push({nrow, ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>vis(m, vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 || j==0 || i==m-1|| j==n-1) && board[i][j]=='O' && !vis[i][j]){
                    bfs(i,j,board, vis);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && !vis[i][j])board[i][j]='X';
            }
        }
        return;
    }
};