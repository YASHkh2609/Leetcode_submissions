class Solution {
public:
    bool rotateString(string s, string goal) {
        string temp="";
        int cnt=0;
        while(cnt<s.length()){
            temp=s.substr(1, s.length()-1);
            temp+=s[0];
            if(temp==goal)return true;
            s=temp;
            cnt++;
        }
        return false;
    }
};