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
        // vector<vector<int>>dp(m, vector<int>(n, -1));
        // return get_minPathSum(m-1, n-1, grid, dp);
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(i==0 && j==0)dp[0][0]=grid[0][0];
        //         else{
        //             int up=INT_MAX, left=INT_MAX;
        //             if(i-1>=0)up = grid[i][j] + dp[i-1][j];
        //             if(j-1>=0)left = grid[i][j] + dp[i][j-1];

        //             dp[i][j]=min(up, left);
        //         }
        //     }
        // }
        // return dp[m-1][n-1];

        //space optimisation

        vector<int>dp(n, INT_MAX);
        for(int i=0;i<m;i++){
            vector<int>temp(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0)temp[0]=grid[0][0];
                else if(j==0)temp[j]=grid[i][j]+dp[j];
                else if(i==0)temp[j]=grid[i][j] + temp[j-1];
                else temp[j] = min(grid[i][j]+ dp[j], grid[i][j]+temp[j-1]);
            }
            dp=temp;
        }
        return dp[n-1];
    }   
};