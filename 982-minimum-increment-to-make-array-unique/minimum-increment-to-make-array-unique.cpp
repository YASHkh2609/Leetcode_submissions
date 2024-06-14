class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // int cnt=0;
        // for(int i=1;i<nums.size();i++){
        //     if(nums[i]<=nums[i-1]){
        //         int new_num=nums[i-1]+1;
        //         cnt+=new_num-nums[i];
        //         nums[i]=new_num;
        //     }
        // }
        // return cnt;
        //count array has been taken of maximum possible with these constraints
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi, nums[i]);
        }
        vector<int>count(nums.size()+ maxi+1, 0);
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
        }
        int ans=0;
        for(int i=0;i<nums.size()+ maxi+1;i++){
            if(count[i]>1){
                ans+=count[i]-1;
                count[i+1]+=count[i]-1;
                count[i]=1;
            }
        }
        return ans;
    }
};