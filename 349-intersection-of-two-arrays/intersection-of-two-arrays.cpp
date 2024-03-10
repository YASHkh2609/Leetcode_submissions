class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, int>mpp;
        for(int i=0;i<nums1.size(); i++){
            if(mpp.find(nums1[i])==mpp.end())mpp[nums1[i]]++;
        }
        for(int j=0;j<nums2.size();j++){
            if(mpp.find(nums2[j])!=mpp.end())mpp[nums2[j]]++;
        }
        vector<int>ans;
        for(auto it: mpp){
            if(it.second>1)ans.push_back(it.first);
        }
        return ans;
        
    }
};