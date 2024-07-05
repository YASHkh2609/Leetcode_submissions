class Solution {
private:
    int get_paths(int row, int col, vector<vector<int>>&dp, vector<vector<int>>& obstacleGrid){
        if(row == 0 && col == 0 && obstacleGrid[row][col]!=1){
            return 1;
        }
        if(obstacleGrid[row][col]==1)return 0;
        if(dp[row][col]!=-1)return dp[row][col];
        int up=0, left=0;

        if(row-1>=0)up = get_paths(row-1, col, dp, obstacleGrid);
        if(col-1>=0)left = get_paths(row, col-1, dp, obstacleGrid);

        return dp[row][col] = up+left;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m, vector<int>(n,-1));

        return get_paths(m-1, n-1, dp, obstacleGrid);
    }
};