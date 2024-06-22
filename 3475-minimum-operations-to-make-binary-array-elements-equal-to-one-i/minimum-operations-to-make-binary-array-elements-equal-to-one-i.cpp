class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int j=0;
        int cnt=0;
        while(j<n){
            if(nums[j]==0){
                int i=j;
                for(i;i<j+3;i++){
                    if(i==n)return -1;
                    nums[i] = !nums[i];
                }
                cnt++;
            }
            j++;
        }
        return cnt;
    }
};