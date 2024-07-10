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
        // vector<vector<int>>dp(n, vector<int>(k+1, -1));
        // return f(n-1, k, nums, dp);

        vector<vector<bool>>dp(n, vector<bool>(k+1, false));

        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }

        if(nums[0]<=k)dp[0][nums[0]]=true;

        for(int ind=1;ind<n;ind++){
            for(int target=1;target<=k;target++){
                bool notPick = dp[ind-1][target];
                bool pick=false;
                if(target>=nums[ind])
                    pick = dp[ind-1][target-nums[ind]];

                dp[ind][target] = (pick || notPick); 
            }
        }
        return dp[n-1][k];
    }
};