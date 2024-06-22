class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(cnt%2==0)cnt++;
            }
            else{
                if(cnt%2!=0)cnt++;
            }
        } 
        return cnt;
    }
};