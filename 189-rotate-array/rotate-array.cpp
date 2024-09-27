class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>temp;
        k = k%n;
        int k_new = n-k;

        int j = 0;
        while(j<k_new){
            temp.push_back(nums[j]);
            j++;
        }
        int i=0;
        while(j<n){
            nums[i]=nums[j];
            i++;
            j++;
        }
        j=0;
        while(j<temp.size()){
            nums[i]=temp[j];
            i++;
            j++;
        }

    }
};