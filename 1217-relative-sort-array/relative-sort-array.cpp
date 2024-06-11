class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int>mpp;
        for(int i=0;i<arr2.size();i++){
            mpp[arr2[i]]=i;
        }
        int ind=arr2.size();
        for(int i=0;i<arr1.size(); i++){
            if(mpp.find(arr1[i])==mpp.end()){
                mpp[arr1[i]]=ind;
                ind++;
            }
        }
        auto compare = [&](int a, int b) { 
            if(mpp[a]>=arr2.size() && mpp[b]>=arr2.size())return a<b;
            return mpp[a] < mpp[b];  
        };
        sort(arr1.begin(), arr1.end(), compare);

        return arr1;
    }
};