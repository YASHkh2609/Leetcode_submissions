class Solution {
private:
    int get_max_money(int ind, vector<int>& nums, vector<int>&dp ){//memoization
        if(ind == 0)return nums[ind];
        if(ind<0)return 0;
        if(dp[ind]!=-1)return dp[ind];
        //pick
        int left = nums[ind] + get_max_money(ind - 2, nums, dp);
        //not pick 
        int right = get_max_money(ind - 1, nums, dp);

        return dp[ind] = max(left, right);
    }
public:
    int rob(vector<int>& nums){ 
        int n=nums.size();
        vector<int>dp(n, -1);
        //return get_max_money(n-1,nums, dp);
        // dp[0]=nums[0];
        // for(int i=1;i<n;i++){
        //     int left  = nums[i];
        //     if(i>1)
        //         left+= dp[i - 2];//pick i
        //     int right = dp[i-1];//not pick i

        //     dp[i]=max(left, right);
        // }
        // return dp[n-1];

        int prev=nums[0];
        int prev2=0;

        for(int i= 1;i<n;i++){
            int left = nums[i];
            if(i>1)left+=prev2;
            int right = prev;

            int cur =max(left, right);

            prev2=prev;
            prev=cur;
        }
        return prev;
    }
};