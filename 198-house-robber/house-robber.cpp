class Solution {
private:
    int get_max_money(int ind, vector<int>& nums, vector<int>&dp ){//memoization
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
        return get_max_money(n-1,nums, dp);
    }
};