class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int cnt=nums.size();
        int flag=0;
        for(int i=0;i<nums.size();i++){
            int orr=0;
            for(int j=i;j<nums.size();j++){
                orr=orr|nums[j];
                if(orr>=k){
                    flag=1;
                    cnt=min(cnt,j-i+1);   
                }
            }
        }
        if(flag==0)return -1;
        return cnt;
    }
};