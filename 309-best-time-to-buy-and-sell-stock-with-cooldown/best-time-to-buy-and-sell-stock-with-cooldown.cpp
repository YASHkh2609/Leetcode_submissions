class Solution {
private:
    int f(int ind, bool buy, vector<int>& prices,vector<vector<int>>&dp){
        if(ind >= prices.size())return 0;
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        int profit=0;
        if(buy){
            profit =max(-prices[ind]+f(ind+1, 0,prices,dp), 0+f(ind+1, 1,prices,dp));
        }
        else{ //cant buy -- sell/ not sell
            profit = max(prices[ind]+f(ind+2, 1,prices,dp), 0+f(ind+1,0,prices,dp));
        }
        return dp[ind][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return f(0, 1, prices, dp);
    }
};