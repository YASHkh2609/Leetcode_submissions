class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // int pos_index=nums.size();
        // int neg_index=-1;
        // if(nums[0]>=0){
        //     pos_index=0;
        // }
        // else if(nums[nums.size()-1]<0){
        //     neg_index=nums.size()-1;
        // }
        // else{
        //     for(int i=0;i<nums.size()-1;i++){
        //         if(nums[i]<0 && nums[i+1]>=0){
        //             neg_index=i;
        //             pos_index=i+1;
        //             break;
        //         }
        //     }
        // }
        // vector<int>ans;
        
        // while(neg_index>=0 && pos_index<nums.size()){
        //     if(nums[neg_index]*nums[neg_index]<=nums[pos_index]*nums[pos_index]){
        //         ans.push_back(nums[neg_index]*nums[neg_index]);
        //         neg_index--;
        //     }
        //     else{
        //         ans.push_back(nums[pos_index]*nums[pos_index]);
        //         pos_index++;
        //     }
        // }
        // while(neg_index==-1 && pos_index<nums.size()){
        //     ans.push_back(nums[pos_index]*nums[pos_index]);
        //     pos_index++;
        // }
        // while(pos_index==nums.size() && neg_index>=0){
        //     ans.push_back(nums[neg_index]*nums[neg_index]);
        //     neg_index--;
        // }
        // return ans;
        int n=nums.size();
        int s=0, e=n-1;
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            if(abs(nums[s])>abs(nums[e])){
                ans[i]=nums[s]*nums[s];
                s++;
            }
            else{
                ans[i]=nums[e]*nums[e];
                e--;
            }
        }
        return ans;
    }
};