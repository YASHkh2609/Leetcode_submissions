class Solution {
public:
    void findCombination(vector<int>&arr, int target, int i, vector<int>& ds, vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        for(int j=i; j<arr.size(); j++){
            if(j>i && arr[j]==arr[j-1])continue;
            if(arr[j]>target)break;
            ds.push_back(arr[j]);
            findCombination(arr, target-arr[j], j+1, ds, ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        findCombination(candidates, target, 0, ds, ans);
        return ans;
    }
};