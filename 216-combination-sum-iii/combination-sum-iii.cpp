class Solution {
public:
    void findCombination(vector<int>& arr, int length,int target, int i, vector<vector<int>>&ans, vector<int>&ds){
        //base case
        if(i==arr.size()){
            if(target==0 && ds.size()==length){
                ans.push_back(ds);
            }
            return;
        }
        //pick element
        if(arr[i]<=target){
            ds.push_back(arr[i]);
            findCombination(arr, length, target-arr[i], i+1, ans, ds);
            ds.pop_back();
        }
        //not picked
        findCombination(arr, length, target, i+1, ans, ds);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>arr={1,2,3,4,5,6,7,8,9};
        vector<vector<int>>ans;
        vector<int>ds;
        findCombination(arr, k, n, 0, ans, ds);
        return ans;
    }
};