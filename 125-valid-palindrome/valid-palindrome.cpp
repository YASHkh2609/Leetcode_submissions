class Solution {
public:
    bool isPalindrome(string s) {
        for(int i=0;i<s.length();i++){
            s[i]=tolower(s[i]);
        }
        vector<char>s1;
        int k=0;
        for(int i=0;i<s.length();i++){
            if(int(s[i])>=97 && int(s[i])<=122 || int(s[i])>=48 && int(s[i])<=57){
                s1.push_back(s[i]);
            }
        }
        int i=0;
        int j=s1.size()-1;
        while(i<j){
            if(s1[i++]!=s1[j--]){
                return false;
            }
        }
        return true;
    }
};