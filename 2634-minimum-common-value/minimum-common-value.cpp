class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        int i=0, j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]==nums2[j]){
                ans=nums1[i];
                break;
            }
            else if(nums1[i]>nums2[j])j++;
            else i++;
        }
        if(ans)return ans;
        return -1;
    }
};