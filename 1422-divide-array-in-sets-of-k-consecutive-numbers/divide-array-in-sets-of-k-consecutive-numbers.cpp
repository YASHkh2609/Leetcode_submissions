class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k!=0)return false;

        map<int, int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;//n x logn
        }

        while(!mpp.empty()){
            int curr=mpp.begin()->first;

            for(int i=0;i<k;i++){
                if(mpp[curr+i]==0)return false;

                mpp[curr+i]--;
                if(mpp[curr+i]==0)mpp.erase(curr+i);
            }
        }
        return true;
    }
};