class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long ans=0;
        int latestOccr=-1;
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1])latestOccr=i-1;
            ans+=i-latestOccr;
        }
        return ans;
    }
};