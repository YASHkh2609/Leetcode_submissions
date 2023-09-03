class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        int mid;
        while(l<=r){
            mid=(l+r)/2;
            if(target==nums[mid])
                return mid;
            else if(target<nums[mid]){
                r=mid-1;
            }
            else {
                l=mid+1;
            }
        }
        return l;
    }
};