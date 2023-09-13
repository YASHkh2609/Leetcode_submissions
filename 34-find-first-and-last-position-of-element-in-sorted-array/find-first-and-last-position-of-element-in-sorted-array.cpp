class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto start=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        auto end=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        end--;
        vector<int> ans;
        if(start!=nums.size() && nums[start]==target){
            ans.push_back(start);
        }
        else
            ans.push_back(-1);
        if(end>=0 && nums[end]==target){
            ans.push_back(end);
        }
        else
            ans.push_back(-1);
        return ans;
    }
};