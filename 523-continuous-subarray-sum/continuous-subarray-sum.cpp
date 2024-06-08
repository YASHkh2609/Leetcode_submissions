class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int, int>mpp; // map sum remainder to index
        int sum=0;
        mpp[0]=-1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            //if(sum%k==0 && i+1>1)return true;
            int rem=sum%k;
            if(mpp.find(rem)==mpp.end())mpp[rem]=i;
            else if(i-mpp[rem]>1){
                return true;
            }
        }
        return  false;
    }
};