class Solution {
private:
    int get_paths(int row, int col, vector<vector<int>>&dp){
        if(row==0 && col == 0)return 1;

        if(dp[row][col]!=-1)return dp[row][col];
        int up=0, left=0;

        if(row-1>=0) up = get_paths(row-1, col, dp);
        if(col-1>=0) left = get_paths(row, col-1, dp);

        return dp[row][col] = up+left;
    }
public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>>dp(m, vector<int>(n,-1));
        // return get_paths(m-1,n-1, dp);

        // for(int row=0;row<m;row++){
        //     for(int col=0;col<n;col++){
        //         if(row==0 && col==0)dp[row][col]=1;
        //         else{
        //             int up=0, left=0;
        //             if(row-1>=0) up = dp[row-1][col];
        //             if(col-1>=0) left = dp[row][col-1];

        //             dp[row][col] = up+ left;
        //         }
        //     }
        // }
        // return dp[m-1][n-1];

        //Space Optimisation

        vector<int>dp(n,0);
        for(int row=0;row<m;row++){
            vector<int>temp(n,0);
            for(int col=0;col<n;col++){
                if(row==0 && col==0)temp[col]=1;
                else{
                    if(col-1>=0)temp[col]= dp[col]+temp[col-1];
                    else temp[col]=dp[col];
                }
            }
            dp=temp;
        }
        return dp[n-1];
    }
};