class Solution {
private:
    int f(int ind, int num_trans,vector<int>& prices, vector<vector<int>>&dp){
        if(ind == prices.size() || num_trans==4)return 0;
        if(dp[ind][num_trans]!=-1)return dp[ind][num_trans];

        int profit=0;
        if(num_trans%2==0){ //num_trans - even ==> buy
            profit=max(-prices[ind]+f(ind+1, num_trans+1,prices,dp),
                        0+f(ind+1, num_trans,prices,dp));
        }
        else{// num_trans - odd ==> sell
            profit =max(prices[ind]+f(ind+1, num_trans+1, prices,dp),
                        0+f(ind+1, num_trans, prices,dp));
        }
        return dp[ind][num_trans]=profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>>dp(n+1, vector<int>(4, -1));
        // return f(0, 0,prices,dp);
        // vector<vector<int>>dp(n+1, vector<int>(5, 0));
        // initialising dp array with 0 so that we dont have to write
        // base case 
        // base case --> dp[n][..]=0, dp[..][2k]=0;
        // for(int ind=n-1;ind>=0;ind--){
        //     for(int num_trans=0;num_trans<4;num_trans++){
        //         int profit=0;
        //         if(num_trans%2==0){ //num_trans - even ==> buy
        //             profit=max(-prices[ind]+dp[ind+1][num_trans+1],
        //                 0+dp[ind+1][num_trans]);
        //         }
        //         else{// num_trans - odd ==> sell
        //             profit =max(prices[ind]+dp[ind+1][num_trans+1],
        //                 0+dp[ind+1][num_trans]);
        //         }
        //         dp[ind][num_trans]=profit;
        //     }
        // }
        // return dp[0][0];
    
        //SPACE OPTIMIZATION
        vector<int>dp(5, 0);
        for(int ind=n-1;ind>=0;ind--){
            vector<int>temp(5, 0);
            for(int num_trans=0;num_trans<4;num_trans++){
                int profit=0;
                if(num_trans%2==0){ //num_trans - even ==> buy
                    profit=max(-prices[ind]+dp[num_trans+1],
                        0+dp[num_trans]);
                }
                else{// num_trans - odd ==> sell
                    profit =max(prices[ind]+dp[num_trans+1],
                        0+dp[num_trans]);
                }
                temp[num_trans]=profit;
            }
            dp=temp;
        }
        return dp[0];
    }
};