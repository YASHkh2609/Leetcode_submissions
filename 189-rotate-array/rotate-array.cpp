class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        /*for(int i=0;i<k;i++){
            int temp1;
            int temp2;
            temp1=nums[0];
            for(int j=0;j<nums.size();j++){
                temp2=nums[(j+1)%nums.size()];
                nums[(j+1)%nums.size()]=temp1;
                temp1=temp2;

            }
        }*/
        int n=nums.size();
        if(k>=n){
            k=k%n;
        }
        if(k>0){
            int arr[k];
            int j=0;
            for(int i=n-k;i<n;i++){
                arr[j]=nums[i];
                j++;
            }
            for(int i=n-k-1;i>=0;i--){
                nums[i+k]=nums[i];
            }
            for(int i=0;i<k;i++){
                nums[i]=arr[i];
            }
            // reverse(nums.begin(),nums.end()-k);
            // reverse(nums.end()-k,nums.end());
            // reverse(nums.begin(),nums.end());
        }
    }
};