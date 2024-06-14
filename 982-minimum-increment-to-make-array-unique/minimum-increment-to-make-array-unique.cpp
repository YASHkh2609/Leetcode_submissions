class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                int new_num=nums[i-1]+1;
                cnt+=new_num-nums[i];
                nums[i]=new_num;
            }
        }
        return cnt;
    }
};