class Solution {
public:
    int get_max_money(vector<int>& arr){
        int n = arr.size();

        int prev=arr[0];
        int prev2=0;

        for(int i=1;i<n;i++){
            int pick = arr[i];
            if(i>1)pick+=prev2;
            int notPick = prev;

            int cur=max(pick, notPick);

            prev2=prev;
            prev=cur;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int>arr1, arr2;
        for(int i=0;i<n;i++){
            if(i!=n-1)arr1.push_back(nums[i]);
            if(i!=0)arr2.push_back(nums[i]);
        }
        return max(get_max_money(arr1), get_max_money(arr2));

    }
};