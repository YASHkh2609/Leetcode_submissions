class Solution {
public:
    string reverseWords(string s) {
        string temp="";
        string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i]==' ' && temp.length()!=0){
                if(ans.length()==0)ans+=temp;
                else ans = temp + " " + ans;
                temp="";
            }
            else if(s[i]!=' ')temp+=s[i];
        }
        if(temp.length()!=0){
            if(ans.length()==0)ans+=temp;
            else ans = temp + " " + ans;
        }
        return ans;
    }
};