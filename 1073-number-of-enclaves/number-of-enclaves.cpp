class Solution {
public:
    void bfs(int row, int col,vector<vector<int>>& grid, vector<vector<int>>&vis ){
        queue<pair<int,int>>q;
        q.push({row, col});
        vis[row][col]=1;
        int m=grid.size();
        int n=grid[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,-1,0,1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nrow=r+delrow[i];
                int ncol=c+delcol[i];

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                    q.push({nrow, ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();        
        vector<vector<int>>vis(m, vector<int>(n,0));
        for(int j=0;j<n;j++){
            if(grid[0][j]==1 && !vis[0][j])bfs(0,j,grid, vis);
            if(grid[m-1][j]==1 && !vis[m-1][j])bfs(m-1,j,grid, vis);
        }
        //traverse first and last column
        for(int i=0;i<m;i++){
            if(grid[i][0]==1 && !vis[i][0])bfs(i,0,grid, vis);
            if(grid[i][n-1]==1 && !vis[i][n-1])bfs(i,n-1,grid, vis);
        }
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j])cnt++;
            }
        }
        return cnt;
    }
};