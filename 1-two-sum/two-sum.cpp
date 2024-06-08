class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();

        unordered_map<int, vector<int>>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]].push_back(i);
        }
        vector<int>ans;

        for(auto it:mpp){
            int remaining=target-it.first;

            if(remaining==it.first)
            {
                if(it.second.size()==2)
                    return it.second;
                else continue;
            }

            auto rem_it=mpp.find(remaining);
            if(rem_it==mpp.end())continue;
            else{
                ans.push_back(it.second[0]);
                ans.push_back(rem_it->second[0]);
                break;
            }
        }
        return ans;
    }    
};