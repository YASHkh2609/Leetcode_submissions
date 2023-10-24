class Solution {
public:
    void findCombination1(vector<int>& arr, int length,int target, int i, vector<vector<int>>&ans, vector<int>&ds){
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
            findCombination1(arr, length, target-arr[i], i+1, ans, ds);
            ds.pop_back();
        }
        //not picked
        findCombination1(arr, length, target, i+1, ans, ds);
    }
    void findCombination2(vector<int>&arr, int length,int target, int i, vector<vector<int>>&ans, vector<int>&ds){
        if(target==0 && ds.size()==length){
            ans.push_back(ds);
            return;
        }
        for(int j=i; j<arr.size(); j++){
            //if(j>i && arr[j]==arr[j-1])continue;
            if(arr[j]>target)break;
            ds.push_back(arr[j]);
            findCombination2(arr,length, target-arr[j], j+1, ans, ds);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>arr={1,2,3,4,5,6,7,8,9};
        vector<vector<int>>ans;
        vector<int>ds;
        findCombination2(arr, k, n, 0, ans, ds);
        return ans;
    }
};