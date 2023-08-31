class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()==nums[nums.size()-1]){
            for(int i=0;i<nums.size()-1;i++){
                if(nums[i+1]-nums[i]==2){
                    return i+1;
                }
            }
        }
        else 
            return nums.size();
        return 0;
    }
};