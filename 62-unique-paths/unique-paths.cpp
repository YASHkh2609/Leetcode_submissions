class Solution {
private:
    int get_paths(int row, int col , int m, int n, vector<vector<int>>&dp){
        if(row==m-1 && col == n-1)return 1;
        if(dp[row][col]!=-1)return dp[row][col];
        int down=0, right=0;

        if(row+1<m)down = get_paths(row+1, col, m, n, dp);
        if(col+1<n)right = get_paths(row, col+1, m,n, dp);

        return dp[row][col] = down+right;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n,-1));
        return get_paths(0,0, m,n, dp);
    }
};