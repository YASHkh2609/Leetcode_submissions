class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>result;  
        int th=floor(nums.size()/3);
        sort(nums.begin(),nums.end());
        int count=1;
        int i=0;
        for(i;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                count++;
            }
            else{
                count=1;
            }
            if(result.empty() && count>th){
                result.push_back(nums[i]);
            }
            else if(count>th && nums[i]!=result.back()){
                result.push_back(nums[i]);   
            }
            
        }
        if(th==0){
            if(nums.size()==1)
                result.push_back(nums[i]);
            else if(nums.size()==2){
                if(nums[i-1]!=nums[i]){
                    result.push_back(nums[i]);
                }
            }
            
        }
        return result;
    }
};