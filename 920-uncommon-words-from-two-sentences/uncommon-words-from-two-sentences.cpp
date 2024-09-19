class Solution {
private:
    void getWords(string s, unordered_map<string, int>&mpp){
        string temp="";
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                mpp[temp]++;
                temp="";
            }
            else{
                temp+=s[i];
            }
        }
        mpp[temp]++;
    }
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int>mpp;
        getWords(s1, mpp);
        getWords(s2, mpp);
        vector<string>ans;
        
        for(auto it:mpp){
            if(it.second==1)ans.push_back(it.first);
        }
        return ans;

    }
};