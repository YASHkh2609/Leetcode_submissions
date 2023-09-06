class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n-i-1;j++){
        //         if(nums[j]>nums[j+1]){
        //             swap(nums[j],nums[j+1]);
        //         }
        //     }
        // }
        int low=0;
        int mid=0;
        int high=n-1;
        while(mid<=high){
            if(nums[mid]<1){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid]>1){
                swap(nums[mid],nums[high]);
                high--;
            }
            else
                mid++;
        }
    }
};