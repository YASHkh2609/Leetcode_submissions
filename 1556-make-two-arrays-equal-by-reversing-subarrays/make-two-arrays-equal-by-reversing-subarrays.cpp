class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int>mpp1;
        unordered_map<int, int>mpp2;

        for(int i=0;i<arr.size();i++){
            mpp1[arr[i]]++;
        }
        for(int j=0;j<target.size();j++){
            mpp2[target[j]]++;
        }

        for(auto it:mpp1){
            if(mpp2[it.first]==0 || mpp2[it.first]!=mpp1[it.first])return false;
        }
        for(auto it:mpp2){
            if(mpp1[it.first]==0 || mpp1[it.first]!=mpp2[it.first])return false;
        }
        return true;
    }
};