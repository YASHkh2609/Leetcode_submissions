class Solution {
private:
    int f(int ind, bool holding_stock, vector<int>& prices,vector<vector<int>>&dp){
        if(ind == prices.size())return 0;
        if(dp[ind][holding_stock]!=-1)return dp[ind][holding_stock];
        int profit=0;
        if(holding_stock){
            profit = max(prices[ind]+f(ind+1, 0,prices,dp), 0+f(ind+1,1,prices,dp));
        }
        else{ //not holding stock
            profit =max(-prices[ind]+f(ind+1, 1,prices,dp), 0+f(ind+1, 0,prices,dp));
        }
        return dp[ind][holding_stock] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        //dp[n+1][2]
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return f(0, 0, prices, dp);
    }
};