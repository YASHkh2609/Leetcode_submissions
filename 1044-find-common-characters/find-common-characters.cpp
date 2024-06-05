class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<vector<int>>hash_arr(words.size(), vector<int>(26,0));

        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].length();j++){
                hash_arr[i][words[i][j]-'a']++;
            }
        }
        vector<string>ans;
        for(int col=0;col<26;col++){
            int mini=101;
            for(int row=0;row<words.size();row++){
                mini=min(mini, hash_arr[row][col]);
            }
            string s="";
            s+= char(col+'a');
            for(int k=0;k<mini;k++){
                ans.push_back(s);
            }
        }
        return ans;
    }
};