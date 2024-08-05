class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int cnt_distinct=0;
        unordered_map<string, int>mpp;
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]]++;
        }
        for(int i=0;i<arr.size();i++){
            if(mpp[arr[i]]==1)cnt_distinct++;
            if(cnt_distinct==k)return arr[i];
        }
        return "";
    }
};