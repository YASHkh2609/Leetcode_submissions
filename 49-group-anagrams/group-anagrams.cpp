class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map< string, vector<string>>umap;
        for(int i=0;i<strs.size();i++){
            vector<int>count(26,0);
            for(int j=0;j<strs[i].length();j++){
                count[strs[i][j]- 'a']++;
            }
            stringstream ss;
            for(int k=0;k<26;k++){
                if(count[k]!=0){
                    ss<<char('a'+k)<<count[k];
                }
            }
            //cout<<ss.str();
            umap[ss.str()].push_back(strs[i]);
        }
        vector<vector<string>> result;
        for(auto itr: umap){
            result.push_back(itr.second);
        }
        return result;
    }
};