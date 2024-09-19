class Solution {
private:
    vector<string> getWords(string s){
        vector<string>vec;
        string temp="";
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                vec.push_back(temp);
                temp="";
            }
            else{
                temp+=s[i];
            }
        }
        vec.push_back(temp);
        return vec;
    }
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string>words1;
        words1 = getWords(s1);
        vector<string>words2;
        words2 = getWords(s2);

        unordered_map<string, int>mpp;
        for(auto it:words1){
            mpp[it]++;
            cout<<it<<" ";
        }
        cout<<endl;
        for(auto it:words2){
            mpp[it]++;
            cout<<it<<" ";
        }

        vector<string>ans;
        for(auto it:mpp){
            if(it.second==1)ans.push_back(it.first);
        }
        return ans;

    }
};