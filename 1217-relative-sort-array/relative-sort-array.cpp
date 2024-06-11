class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int>mpp;
        for(int i=0;i<arr2.size();i++){
            mpp[arr2[i]]=i+1;
        }

        for(int i=0;i<arr1.size();i++){
            if(mpp[arr1[i]]==0)mpp[arr1[i]]=1001;
        }

        auto compare = [&](int a, int b) { 
            if(mpp[a] == mpp[b])return a<b;
            return mpp[a] < mpp[b];  
        };
        sort(arr1.begin(), arr1.end(), compare);

        return arr1;
    }
};