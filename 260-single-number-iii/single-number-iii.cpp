class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorr=0;
        int xorr1=0;//for ith bit set
        int xorr2=0;//for ith bit unset
        for(int i=0;i<nums.size();i++){
            xorr=xorr^nums[i];
        }
        int setbit=0;
        for(int i=0;i<32;i++){
            if((xorr&(1<<i))!=0){
                setbit=i;
                break;
            }
        }
        for(int i=0;i<nums.size();i++){
            if((nums[i] & (1<<setbit))==0)xorr2=xorr2^nums[i];
            else xorr1=xorr1^nums[i];
        }
        vector<int>ans;
        ans.push_back(xorr1);
        ans.push_back(xorr2);
        return ans;
    }
};