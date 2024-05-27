class Solution {
public:
    int specialArray(vector<int>& nums) {
        int maxi=-1;
        for(int i=0;i<nums.size();i++){
            maxi=max(nums[i], maxi);
        }
        int ans=-1;
        vector<int>freq(maxi+1, 0);
        for(int i=1;i<=maxi;i++){
            for(int j=0;j<nums.size();j++){
                if(nums[j]>=i)freq[i]++;
            }
            if(i==freq[i])ans=freq[i];
        }
        return ans;
    }
};