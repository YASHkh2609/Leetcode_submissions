class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int cnt_zeros=0;
        int swaps = INT_MAX;
        int n = nums.size();
        int total=0;//cnt of ones
        for(int i=0;i<n;i++){
            if(nums[i]==1)total++;
        }
        int i=0, j=0;
        int windowSize=0;
        while(i<n){
            while(windowSize<total){
                if(nums[j]==0)cnt_zeros++;
                j=(j+1)%n;
                windowSize++;
            }
            swaps=min(cnt_zeros, swaps);
            if(nums[i]==0)cnt_zeros--;
            windowSize--;
            i++;
        }
        return swaps;
    }
};