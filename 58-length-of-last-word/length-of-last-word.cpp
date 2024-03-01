class Solution {
public:
    int lengthOfLastWord(string s) {
        string ans="";
        string temp="";
        for(int i=0; i<s.length();i++){
            if(int(s[i])!=32){
                temp+=s[i];
            }
            else{
                if(temp.length())ans=temp;
                temp="";            
            }
        }
        if(temp.length())ans=temp;
        return ans.length();
    }
};