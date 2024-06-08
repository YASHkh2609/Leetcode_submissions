class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int, int>mpp;

        //Two Pass Hashing
        // for(int i=0;i<n;i++){
        //     mpp[nums[i]]=i;
        // }
        // vector<int>ans;

        // for(int i=0;i<n;i++){
        //     int complement=target-nums[i];
        //     if(mpp.find(complement)!=mpp.end() && mpp[complement]!=i){
        //         ans.push_back(i);
        //         ans.push_back(mpp[complement]);
        //         break;
        //     }
        // }
        // return ans;

        //One pass
        for(int i=0;i<n;i++){
            int complement=target-nums[i];

            if(mpp.find(complement)==mpp.end())mpp[nums[i]]=i;

            else{
                return {i, mpp[complement]};
            }
        }
        return {};
    }    
};