class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int>hash_arr(26, INT_MAX);

        for(int i=0;i<words.size();i++){
            vector<int>temp(26,0);
            for(int j=0;j<words[i].length();j++){
                temp[words[i][j]-'a']++;
            }
            for(int k=0;k<26;k++){
                hash_arr[k]=min(hash_arr[k], temp[k]);
            }
        }

        vector<string>ans;
        for(int i=0;i<26;i++){
            for(int j=0;j<hash_arr[i];j++){
                ans.push_back(string(1,i+'a'));
            }
        }
        return ans;
    }
};