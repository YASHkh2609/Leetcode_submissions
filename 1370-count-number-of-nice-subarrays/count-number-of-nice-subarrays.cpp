class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0)nums[i]=0;
            else nums[i]=1;
        }
        int presum=0;
        unordered_map<int, int>mpp; //prefix sum -> its count
        mpp[0]=1;
        int cnt=0;

        for(int i=0;i<nums.size();i++){
            presum+=nums[i];
            if(mpp.find(presum-k)!=mpp.end()){
                cnt+=mpp[presum-k];
            }
            mpp[presum]++;
        }

        return cnt;
    }
};