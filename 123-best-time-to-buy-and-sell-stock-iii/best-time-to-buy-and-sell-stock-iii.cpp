class Solution {
private:
    int f(int ind, int buy, int cap, vector<int>& prices,vector<vector<vector<int>>>&dp){
        if(ind==prices.size() || cap==0)return 0;
        if(dp[ind][buy][cap]!=-1)return dp[ind][buy][cap];
        int profit=0;

        if(buy){
            profit=max(-prices[ind]+f(ind+1, 0, cap, prices,dp), 0+f(ind+1, 1, cap, prices,dp));
        }
        else{
            profit=max(prices[ind]+f(ind+1, 1, cap-1, prices,dp), 0+f(ind+1, 0, cap, prices,dp));
        }
        return dp[ind][buy][cap] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3,-1)));
        // return f(0, 1, 2, prices,dp);
        //base case
        //ind==n
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3,0)));
        //above we have initialised our dp with 0 so we dont need to write base case
        // for(int j=0;j<=1;j++){
        //     for(int k=0;k<=2;k++){
        //         dp[n][j][k]=0;
        //     }
        // }
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=1;j++){
        //         dp[i][j][0]=0;
        //     }
        // }

        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    int profit=0;
                    if(buy){
                        profit=max(-prices[ind]+dp[ind+1][0][cap],
                                   0+dp[ind+1][1][cap]);
                    }
                    else{
                        profit=max(prices[ind]+dp[ind+1][1][cap-1],
                                  0+dp[ind+1][0][cap]);
                    }

                    dp[ind][buy][cap]=profit;
                }
            }
        }
        return dp[0][1][2];
    }
};