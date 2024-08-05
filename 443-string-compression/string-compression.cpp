class Solution {
public:
    int compress(vector<char>& chars) {
        string s="";
        int i=0,j=1;
        int cnt=1;
        while(i<chars.size()){
            if(j<chars.size() && chars[i]==chars[j]){
                cnt++;
                j++;
            }
            else{
                if(cnt==1){
                    s+=chars[i];
                }
                else{
                    s+=chars[i];
                    s+=to_string(cnt);
                }
                i=j;
                j++;
                cnt=1;
            }
        }
        chars.clear();
        for(int i=0;i<s.length();i++){
            chars.push_back(s[i]);
        }
        return s.length();
    }
};