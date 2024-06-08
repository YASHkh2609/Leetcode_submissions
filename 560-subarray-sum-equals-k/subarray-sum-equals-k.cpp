class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        int sum=0;
        int n=nums.size();
        map<int, int>presum_count;//mapping sum->count of that sum
        presum_count[0]=1;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem=sum-k;
            count+=presum_count[rem];
            presum_count[sum]++;
        }
        
        return count;
    }
};