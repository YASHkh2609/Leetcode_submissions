class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int mod = int(1e9+7);
        vector<int>sums;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j]%mod;
                sums.push_back(sum);
            }
        }
        sort(sums.begin(), sums.end());
        int ans=0;
        for(int i=left-1;i<right;i++){
            ans+=(sums[i]%mod);
            ans=ans%mod;
        }
        return (ans%mod);
    }
};