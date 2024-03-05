class Solution {
public:
    int minimumLength(string s) {
        int i=0;
        int j=s.length()-1;
        cout<<s.length();
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                if(i>0 && s[i]==s[i-1])i++;
                else if((j<s.length()-1) && s[j]==s[j+1])j--;
                else break;
            }
            
        }
        if(i==j && i>0  && s[i]==s[i-1])i++;
        return j-i+1;
    }
};