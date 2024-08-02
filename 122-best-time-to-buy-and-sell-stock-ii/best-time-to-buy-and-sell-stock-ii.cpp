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
        vector<vector<int>>dp(n, vector<int>(2, -1));
        return getmaxProfit(0, 1, prices, dp);
    }
};