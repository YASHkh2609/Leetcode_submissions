class Solution {
public:
    int minOperations(vector<int>& nums) {
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