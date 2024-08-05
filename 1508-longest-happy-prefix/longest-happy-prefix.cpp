class Solution {
public:
    string longestPrefix(string s) {
        vector<int>LPS(s.length(),0);
        int length=0, i=1;
        while(i<s.length()){
            if(s[i]==s[length]){
                length++;
                LPS[i]=length;
                i++;
            }
            else{
                if(length>0){
                    length = LPS[length-1];
                }
                else{
                    LPS[i]=0;
                    i++;
                }
            }
            
        }
        return s.substr(0, LPS[s.length()-1]);
    }
};

// acccbaaacccbaac
// 00000111234567