class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>csum;
        int sum;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            csum.push_back(sum);
        }
        return csum;
    }
};