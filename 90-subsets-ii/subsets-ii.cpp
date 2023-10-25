class Solution {
public:
    void Subset(vector<int>& nums,int index,vector<int>& ds,vector<vector<int>>&ans){
        ans.push_back(ds);

        for(int i=index; i<nums.size(); i++){
            if(i>index && nums[i]==nums[i-1])continue;
            ds.push_back(nums[i]);
            Subset(nums,i+1,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        sort(nums.begin(),nums.end());
        Subset(nums,0,ds,ans);
        return ans;
    }
};