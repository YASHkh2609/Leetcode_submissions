class Solution {
private:
    int get_max_money(int ind, int n, vector<int>& nums, vector<int>&dp ){
        if(ind>=n)return 0;
        if(dp[ind]!=-1)return dp[ind];
        //pick
        int left = nums[ind] + get_max_money(ind + 2, n , nums, dp);
        //not pick 
        int right = get_max_money(ind + 1, n , nums, dp);

        return dp[ind] = max(left, right);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n, -1);
        return get_max_money(0,n,nums, dp);
    }
};