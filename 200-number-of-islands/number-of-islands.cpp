class Solution {
private:
    void bfs(int row, int col,vector<vector<int>>&vis,vector<vector<char>>& grid){
        queue<pair<int, int>>q;
        vis[row][col]=1;
        q.push({row,col});

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            int m=grid.size();
            int n=grid[0].size();

            if((row-1)>=0 && !vis[row-1][col] && grid[row-1][col]=='1'){
                q.push({row-1, col});
                vis[row-1][col]=1;
            }
            if(col-1>=0 && !vis[row][col-1] && grid[row][col-1]=='1'){
                q.push({row, col-1});
                vis[row][col-1]=1;
            }
            if((row+1)<m && !vis[row+1][col] && grid[row+1][col]=='1'){
                q.push({row+1, col});
                vis[row+1][col]=1;
            }
            if((col+1)<n && !vis[row][col+1] && grid[row][col+1]=='1'){
                q.push({row, col+1});
                vis[row][col+1]=1;
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        vector<vector<int>> vis(m, vector<int> (n,0));

        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(!vis[row][col] && grid[row][col]=='1'){
                    bfs(row, col, vis, grid);
                    cnt++;
                }
            }
        }
        return cnt;   
    }
};