class Solution {
public:
    void moveZeroes(vector<int>& nums) {
         int n=nums.size();
        //cout<<n;
        //vector<int>ans;
        int i=0;
        int j;
        for(j=1;j<n;j++){
            if(nums[i]==0 && nums[j]!=0){
                nums[i]=nums[j];
                nums[j]=0;
                i++;
            }
            else if(nums[i]!=0)
                i++;
        }
    }
};