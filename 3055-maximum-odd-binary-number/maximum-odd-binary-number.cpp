class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt=0;//count of 1s;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1')cnt++;
        }
        //cout<<cnt;
        string ans="";
        while(cnt>1){
            ans+='1';
            cnt--;
        }

        while(ans.length()<s.length()-1)ans+='0';
        ans+='1';
        return ans;
    }
};