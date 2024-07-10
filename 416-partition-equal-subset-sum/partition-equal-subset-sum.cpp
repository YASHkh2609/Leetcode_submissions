class Solution {
private:
    bool f(int ind, int target,vector<int>& nums,vector<vector<int>>&dp){
        if(target==0)return true;
        if(ind==0)return (target == nums[0]);
        if(dp[ind][target]!=-1)return dp[ind][target];
        bool notPick = f(ind-1, target, nums, dp);
        bool pick=false;
        if(target>=nums[ind])
            pick = f(ind-1, target-nums[ind], nums, dp);

        return dp[ind][target] = (pick || notPick);
    }
    

public:
    bool canPartition(vector<int>& nums) {
        int S=0;
        for(int i=0;i<nums.size();i++){
            S+=nums[i];
        }
        int n = nums.size();
        if(S%2!=0)return false;

        int k = S/2;
        vector<vector<int>>dp(n, vector<int>(k+1, -1));
        return f(n-1, k, nums, dp);
    }
};