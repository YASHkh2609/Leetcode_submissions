class Solution {
private:
    int f(int ind, bool buy, vector<int>& prices,vector<vector<int>>&dp){
        if(ind == prices.size())return 0;
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        int profit=0;
        if(buy){
            profit =max(-prices[ind]+f(ind+1, 0,prices,dp), 0+f(ind+1, 1,prices,dp));
        }
        else{ //cant buy -- sell/ not sell
            profit = max(prices[ind]+f(ind+1, 1,prices,dp), 0+f(ind+1,0,prices,dp));
        }
        return dp[ind][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        //dp[n+1][2]
        int n=prices.size();
        // vector<vector<int>>dp(n+1,vector<int>(2,-1));
        // // return f(0, 1, prices, dp);
        // dp[n][0]=0;
        // dp[n][1]=0;
        // for(int ind=n-1;ind>=0;ind--){
        //     for(int buy=0;buy<=1;buy++){
        //         int profit=0;
        //         if(buy){
        //             profit=max(-prices[ind]+dp[ind+1][0], 0+dp[ind+1][1]);
        //         }
        //         else{ //cant buy -- sell/ not sell
        //             profit = max(prices[ind]+dp[ind+1][1], 0+dp[ind+1][0]);
        //         }
        //         dp[ind][buy]=profit;
        //     }
        // }
        // return dp[0][1];

        vector<int>dp(2,0);
        for(int ind=n-1;ind>=0;ind--){
            vector<int>temp(2,-1);
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                if(buy){
                    profit=max(-prices[ind]+dp[0], 0+dp[1]);
                }
                else{ //cant buy -- sell/ not sell
                    profit = max(prices[ind]+dp[1], 0+dp[0]);
                }
                temp[buy]=profit;
            }
            dp=temp;
        }
        return dp[1];
    }
};