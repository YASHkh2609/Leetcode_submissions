class Solution {
private:
    int get_minPathSum(int i, int j, vector<vector<int>>& grid, vector<vector<int>>&dp){
        if(i==0 && j==0)return grid[0][0];
        if(dp[i][j]!=-1)return dp[i][j];
        int up=INT_MAX, left=INT_MAX;

        if(i-1>=0)up = grid[i][j] + get_minPathSum(i-1, j, grid, dp);
        if(j-1>=0)left = grid[i][j] + get_minPathSum(i, j-1, grid, dp);

        return dp[i][j]= min(up, left);

    }
public:
    int minPathSum(vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return get_minPathSum(m-1, n-1, grid, dp);
    }   
};