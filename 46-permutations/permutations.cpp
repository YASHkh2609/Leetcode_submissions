class Solution {
public:
    void recurPermute1(vector<int>& nums,vector<int>& ds,vector<vector<int>>&ans, int freq[]){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                freq[i]=1;
                ds.push_back(nums[i]);
                recurPermute1(nums,ds,ans,freq);
                freq[i]=0;
                ds.pop_back();
            }
        }
    }
    void recurPermute2(vector<int>& nums,int ind,vector<vector<int>>&ans){
        if(ind==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[i],nums[ind]);
            recurPermute2(nums,ind+1,ans);
            swap(nums[i],nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        //vector<int>ds;
        //int freq[21]={0};
        //recurPermute1(nums,ds,ans,freq);
        recurPermute2(nums,0,ans);
        return ans;
    }
};