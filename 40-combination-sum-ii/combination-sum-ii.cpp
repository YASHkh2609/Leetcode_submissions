class Solution {
private:
    void getCombination(int ind, int target, vector<int>&ds, vector<vector<int>>&ans,
    vector<int>&arr){
        if(target==0){
            ans.push_back(ds);
            return;
        }

        for(int j=ind;j<arr.size();j++){
            if(j>ind && arr[j] == arr[j-1])continue;
            if(arr[j]>target)break;
            ds.push_back(arr[j]);
            getCombination(j+1, target-arr[j], ds, ans, arr);
            ds.pop_back();
        }
      
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        sort(candidates.begin(), candidates.end());
        int n=candidates.size();
        getCombination(0, target,ds, ans, candidates);
        return ans;

    }
};