class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int, int>mpp; //rem:count
        int sum=0;
        int count=0;
        mpp[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int rem=sum%k;

            if(rem<0)rem+=k;
            count+=mpp[rem];
            mpp[rem]++;
        }
        return count;
    }
};