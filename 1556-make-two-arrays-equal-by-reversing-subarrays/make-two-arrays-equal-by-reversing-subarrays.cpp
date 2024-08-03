class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        // unordered_map<int, int>mpp1;
        // unordered_map<int, int>mpp2;

        // for(int i=0;i<arr.size();i++){
        //     mpp1[arr[i]]++;
        // }
        // for(int j=0;j<target.size();j++){
        //     mpp2[target[j]]++;
        // }

        // for(auto it:mpp1){
        //     if(mpp2[it.first]==0 || mpp2[it.first]!=mpp1[it.first])return false;
        // }
        // return true;

        unordered_map<int, int>mpp;
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]]++;
        }

        for(int j=0;j<target.size();j++){
            if(mpp.find(target[j])==mpp.end())return false;
            mpp[target[j]]--;
            if(mpp[target[j]]==0)mpp.erase(target[j]);
        }
        return true;
    }
};