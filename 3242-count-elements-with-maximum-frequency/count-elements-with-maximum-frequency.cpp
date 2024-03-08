class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int>mpp;
        int max=0;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
            if(max<mpp[nums[i]])max=mpp[nums[i]];
        }
        int ans=0;
        for(auto it:mpp){
            if(it.second==max)ans+=it.second;
        }
        return ans;
    }
};