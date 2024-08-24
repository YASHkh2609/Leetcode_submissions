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
        // vector<vector<int>>dp(n+1,vector<int>(2,-1));
        // return f(0, 1, prices, dp);
        // vector<vector<int>>dp(n+2,vector<int>(2,-1));
        // dp[n][0]=0;
        // dp[n][1]=0;
        // dp[n+1][0]=0;
        // dp[n+1][1]=0;
        // for(int ind=n-1;ind>=0;ind--){
        //     for(int buy=0;buy<=1;buy++){
        //         int profit=0;
        //         if(buy){
        //             profit=max(-prices[ind]+dp[ind+1][0], 0+dp[ind+1][1]);
        //         }
        //         else{ //cant buy -- sell/ not sell
        //             profit = max(prices[ind]+dp[ind+2][1], 0+dp[ind+1][0]);
        //         }
        //         dp[ind][buy]=profit;
        //     }
        // }
        // return dp[0][1];
        vector<int>prev1(2,0);//ind+1
        vector<int>prev2(2,0);//ind+2

        for(int ind=n-1;ind>=0;ind--){
            vector<int>temp(2,-1);
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                if(buy){
                    profit=max(-prices[ind]+prev1[0], 0+prev1[1]);
                }
                else{ //cant buy -- sell/ not sell
                    profit = max(prices[ind]+prev2[1], 0+prev1[0]);
                }
                temp[buy]=profit;
            }
            prev2=prev1;
            prev1=temp;
        }
        return prev1[1];
    }
};