class Solution {
private:
    void get_subset_sums(int ind, int sum, int start, int end, vector<int>& nums, vector<int>&sums){
        if(ind>end){
            sums.push_back(sum);
            return;
        }
        sum +=nums[ind];
        get_subset_sums(ind+1, sum, start, end, nums, sums);
        sum-= nums[ind];

        get_subset_sums(ind+1, sum, start, end, nums, sums);
    }
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        vector<int>sum_half1;
        vector<int>sum_half2;
        int n = nums.size();
        get_subset_sums(0, 0, 0, n/2, nums, sum_half1);
        get_subset_sums(n/2+1, 0, n/2+1, n-1, nums, sum_half2);

        sort(sum_half2.begin(), sum_half2.end());
        int ans=INT_MAX;
        for(int i=0;i<sum_half1.size();i++){
            int val1 = sum_half1[i];
            int rem = goal-val1;

            int ptr = lower_bound(sum_half2.begin(), sum_half2.end(), rem)-sum_half2.begin();
            //lower_bound gives to rem if it exists and 
            //if it doesnt then it will give pointer to next higher element
            int val2 = 0;
            int sum=0;
            if(ptr==0){
                val2 = sum_half2[0];
                sum=val1+val2;
                ans = min(ans, abs(sum-goal));
            }
            else if(ptr==sum_half2.size()){
                val2 = sum_half2[sum_half2.size()-1];
                sum=val1+val2;
                ans = min(ans, abs(sum-goal));
            }
            else{
                int sum1= val1 + sum_half2[ptr];
                int sum2=val1 + sum_half2[ptr-1];
                ans = min(ans, min(abs(sum1- goal), abs(sum2-goal)));
            }
        }
        return ans;
    }
};