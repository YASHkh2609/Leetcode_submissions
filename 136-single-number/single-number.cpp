class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int flag=0;
        int i;
        for(i=0;i<nums.size()-1;i++){
            if(nums[i+1]==nums[i]){
                flag=1;
            }
            else if(nums[i+1]!=nums[i] && flag==1){
                flag=0;
            }
            else if(nums[i+1]!=nums[i] && flag==0){
                return nums[i]; 
            }
        }
        return nums[i];

    }
};