class Solution {
private:
    int get_paths(int row, int col, vector<vector<int>>&dp){
        if(row==0 && col == 0)return 1;

        if(dp[row][col]!=-1)return dp[row][col];
        int way1=0, way2=0;

        if(row-1>=0) way1 = get_paths(row-1, col, dp);
        if(col-1>=0) way2 = get_paths(row, col-1, dp);

        return dp[row][col] = way1+way2;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n,-1));
        // return get_paths(m-1,n-1, dp);
        for(int i=0;i<n;i++)dp[0][i]=1;
        for(int i=0;i<m;i++)dp[i][0]=1;

        for(int row=1;row<m;row++){
            for(int col=1;col<n;col++){
                int way1=0, way2=0;
                if(row-1>=0) way1 = dp[row-1][col];
                if(col-1>=0) way2 = dp[row][col-1];

                dp[row][col] = way1+ way2;
            }
        }
        return dp[m-1][n-1];

    }
};