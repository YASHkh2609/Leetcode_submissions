class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort(t.begin(),t.end());
        // sort(s.begin(),s.end());
        // if(t==s)return true;
        // else return false;
        int freq_arr1[26]={0};
        int freq_arr2[26]={0};
        if(s.length()==t.length()){
            for(int i=0;i<s.length();i++){
                freq_arr1[int(s[i])-int('a')]++;
                freq_arr2[int(t[i])-int('a')]++;
            }
            for(int i=0;i<26;i++){
                if(freq_arr1[i]!=freq_arr2[i])
                    return false;
            }
            return true;
        }
        else
            return false;
        return 0;
    }
};