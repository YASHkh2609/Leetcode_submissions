class Solution {
public:
    static bool cmp(pair<char, int>&a, pair<char, int>&b){
        return a.second>b.second;
    }
    string frequencySort(string s) {
        unordered_map<char, int>umap;
        for(int i=0;i<s.length();i++){
            umap[s[i]]++;
        }
        vector<pair<char, int>>vec;

        for(auto it: umap){
            vec.push_back(it);
        }

        sort(vec.begin(),vec.end(),cmp);
        string ans="";
        for(auto it: vec){
            while(it.second--){
                ans+=it.first;
            }
        }
        return ans;
    }
};