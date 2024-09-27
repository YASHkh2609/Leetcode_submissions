class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev=0;
        int cur=1;
        while(cur<nums.size()){
            if(nums[prev]==nums[cur]){
                cur++;
            }
            else{
                prev++;
                nums[prev]=nums[cur];
                cur++;
            }
        }
        return prev+1;
    }
};