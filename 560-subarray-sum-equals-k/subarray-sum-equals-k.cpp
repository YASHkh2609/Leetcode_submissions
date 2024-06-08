class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        int n=nums.size();
        vector<int>prefix_arr(n, 0);
        prefix_arr[0]=nums[0];
        if(prefix_arr[0]==k)count++;
        for(int i=1;i<n;i++){
            prefix_arr[i]=nums[i]+prefix_arr[i-1];
            if(prefix_arr[i]==k)count++;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int sum_ij=prefix_arr[j]-prefix_arr[i];
                if(sum_ij==k)count++;
            }
        }
        return count;
    }
};