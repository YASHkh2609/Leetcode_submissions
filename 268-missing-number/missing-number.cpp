class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long sum_arr=0;
        int max=0,min=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>max)max=nums[i];
            if(nums[i]<min)min=nums[i];
            sum_arr+=nums[i];
        }
        long long n_sum = (max*(max+1))/2;
        if(min!=0)return 0;
        else if(n_sum-sum_arr==0)return max+1;
        return n_sum-sum_arr;
    }
};