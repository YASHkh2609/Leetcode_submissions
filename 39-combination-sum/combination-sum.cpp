class Solution {
public:
    void findCombination(vector<int>& arr, int target, int i, vector<vector<int>>&ans, vector<int>&ds){
        if(i==arr.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }

        if(arr[i]<=target){
            ds.push_back(arr[i]);
            findCombination(arr, target-arr[i], i, ans, ds);
            ds.pop_back();
        }
        findCombination(arr, target, i+1, ans, ds);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        findCombination(candidates, target, 0, ans, ds);
        return ans;
    }
};