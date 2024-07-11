class Solution {
private:
    void get_subset_sums(int ind, int sum,  int len, int end,
     vector<int>& nums, vector<vector<int>>&sums){
        if(ind>end){
            sums[len].push_back(sum);
            return;
        }
        sum +=nums[ind];
        get_subset_sums(ind+1, sum,len+1, end, nums, sums);
        sum-= nums[ind];

        get_subset_sums(ind+1, sum, len, end, nums, sums);
    }
    int f(vector<int>&sum_half1, vector<int>&sum_half2, int goal){
        sort(sum_half2.begin(), sum_half2.end());

        int sum=INT_MIN;

        for(int i=0;i<sum_half1.size();i++){
            int val1 = sum_half1[i];
            int rem = goal-val1;

            int ptr = lower_bound(sum_half2.begin(), sum_half2.end(), rem)-sum_half2.begin();
            //lower_bound gives to rem if it exists and 
            //if it doesnt then it will give pointer to next higher element
            int val2 = 0;
            if(ptr==0){
                if(sum_half2[0]!=rem)continue;
                val2 = sum_half2[0];
                sum=max(sum, val1+val2);
            }
            else if(ptr==sum_half2.size()){
                val2 = sum_half2[sum_half2.size()-1];
                sum=max(sum, val1+val2);
            }
            else{
                if(sum_half2[ptr]>rem)val2=sum_half2[ptr-1];
                else val2=sum_half2[ptr];
                sum=max(sum, val1+val2);
            }
        }
        // cout<<sum<<" _1"<<endl;
        return sum;
    }
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>arr1((n/2)+1);
        vector<vector<int>>arr2((n/2)+1);
        
        get_subset_sums(0, 0, 0, n/2-1, nums, arr1);
        get_subset_sums(n/2, 0,0, n-1, nums, arr2);

        int totalSum=0;
        for(int i=0;i<n;i++){
            totalSum+=nums[i];
        }
        int goal = totalSum/2;

        int sum_partition1=INT_MIN;
        for(int i=0;i<=n/2;i++){
            int len_subset_arr1=i;//k
            int len_subset_arr2=n/2-i;//n-k

            sum_partition1=max(sum_partition1,f(arr1[len_subset_arr1], arr2[len_subset_arr2],goal));
        }
        // cout<<sum_partition1<<" "<<goal;
        int sum_partition2 = totalSum - sum_partition1;
        return abs(sum_partition2-sum_partition1);

    }
};