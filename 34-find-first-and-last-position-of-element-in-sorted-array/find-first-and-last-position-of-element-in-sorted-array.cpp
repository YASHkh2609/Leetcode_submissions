class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto start=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        auto end=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        end--;
        vector<int> ans(2,0);
        if(start!=nums.size() && nums[start]==target){
            ans[0]=start;
        }
        else
            ans[0]=-1;
        if(end>=0 && nums[end]==target){
            ans[1]=end;
        }
        else
            ans[1]=-1;
        return ans;
    }
};