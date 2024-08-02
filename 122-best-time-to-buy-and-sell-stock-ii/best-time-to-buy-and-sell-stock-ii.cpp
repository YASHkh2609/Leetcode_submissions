class Solution {
private:
    int getmaxProfit(int ind, int buy, vector<int>& prices, vector<vector<int>>&dp){
        if(ind == prices.size()){
            return 0;
        }
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        int profit=0;
        if(buy){ // i'm not holding a stock
            profit = max(-prices[ind]+getmaxProfit(ind+1, 0, prices,dp), 0+getmaxProfit(ind+1, 1, prices, dp));
        }
        else{//holding a stock
            profit = max(prices[ind]+getmaxProfit(ind+1, 1, prices,dp),0+getmaxProfit(ind+1, 0, prices, dp));
        }
        return dp[ind][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>>dp(n, vector<int>(2, -1));
        // return getmaxProfit(0, 1, prices, dp);
        // vector<vector<int>>dp(n+1, vector<int>(2, -1));

        // dp[n][0]=0;
        // dp[n][1]=0;

        // for(int ind=n-1;ind>=0;ind--){
        //     for(int buy=0;buy<=1;buy++){
        //         int profit=0;
        //         if(buy){ // i'm not holding a stock
        //             profit = max(-prices[ind]+dp[ind+1][0], 0+dp[ind+1][1]);
        //         }
        //         else{//holding a stock
        //             profit = max(prices[ind]+dp[ind+1][1],0+dp[ind+1][0]);
        //         }
        //         dp[ind][buy] = profit;
        //     }
        // }
        // return dp[0][1];

        vector<int>dp(2, -1);
        dp[0]=0;
        dp[1]=0;
        for(int ind=n-1;ind>=0;ind--){
            vector<int>temp(2,-1);
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                if(buy){ // i'm not holding a stock
                    profit = max(-prices[ind]+dp[0], 0+dp[1]);
                }
                else{//holding a stock
                    profit = max(prices[ind]+dp[1],0+dp[0]);
                }
                temp[buy] = profit;
            }
            dp=temp;
        }
        return dp[1];


    }
};