class Solution {
public:
    vector<int>rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        // vector<int> pos;
        // vector<int> neg;
        //vector<int>result;
        // for(int i=0;i<n;i++){
        //     if(nums[i]<0){
        //         neg.push_back(nums[i]);
        //     }
        //     else
        //         pos.push_back(nums[i]);
        // }
        // for(int i=0;i<n/2;i++){
        //     result.push_back(pos[i]);
        //     result.push_back(neg[i]);
        // }
        int pIndex=0;
        int nIndex=1;
        vector<int>result(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                result[pIndex]=nums[i];
                pIndex+=2;
            }
            else{
                result[nIndex]=nums[i];
                nIndex+=2;
            }
        }
        return result;
    }
};