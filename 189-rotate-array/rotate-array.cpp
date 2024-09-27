class Solution {
private:
    void reverse_arr(vector<int>& nums, int start, int end){
        while(start<end){
            swap(nums[start++], nums[end--]);
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k = k%n;

        int start1 = 0;
        int end1= n-k-1;
        int start2 =n-k;
        int end2=n-1;

        reverse_arr(nums, start1, end1);
        reverse_arr(nums, start2, end2);

        reverse_arr(nums, 0, n-1);
        
    }
};