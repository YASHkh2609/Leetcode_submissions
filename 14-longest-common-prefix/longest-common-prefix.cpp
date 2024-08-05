class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        if(strs.size()==0)return "";
        if(strs.size()==1)return strs[0];
        string prefix="";
        for(int i=0;i<strs.size();i++){
            int j=0;
            if(i==0){
                string s1=strs[i];
                string s2=strs[i+1];
                while(j<min(s1.length(), s2.length())){
                    if(s1[j]==s2[j]){
                        prefix+=s1[j];
                        j++;
                    }
                    else break;
                }
                if(prefix=="")return prefix;
            }
            else{
                string s=strs[i];
                if(s.length()==0)return "";
                while(j<min(s.length(), prefix.length())){
                    if(s[j]==prefix[j])j++;
                    else{
                        prefix.erase(j, prefix.length()-j);
                    }
                }
                if(prefix=="")return prefix;
            }
            
        }
        return prefix;
    }
};