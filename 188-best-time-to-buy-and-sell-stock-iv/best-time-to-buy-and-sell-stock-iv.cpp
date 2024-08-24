class Solution {
private:
    int f(int ind, int num_trans,int k,vector<int>& prices, vector<vector<int>>&dp){
        if(ind == prices.size() || num_trans==2*k)return 0;
        if(dp[ind][num_trans]!=-1)return dp[ind][num_trans];

        int profit=0;
        if(num_trans%2==0){ //num_trans - even ==> buy
            profit=max(-prices[ind]+f(ind+1, num_trans+1,k, prices,dp),
                        0+f(ind+1, num_trans, k, prices,dp));
        }
        else{// num_trans - odd ==> sell
            profit =max(prices[ind]+f(ind+1, num_trans+1, k, prices,dp),
                        0+f(ind+1, num_trans, k, prices,dp));
        }
        return dp[ind][num_trans]=profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2*k, -1));
        return f(0, 0, k, prices,dp);
    }
};