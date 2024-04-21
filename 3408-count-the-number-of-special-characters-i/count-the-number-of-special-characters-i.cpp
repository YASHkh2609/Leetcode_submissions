class Solution {
public:
    int numberOfSpecialChars(string word) {
        bool lower[26]={false};
        bool upper[26]={false};

        for(int i=0;i<word.length();i++){
            if(word[i]>=65 && word[i]<=90){
                upper[word[i]-'A']=true;
            }
            else{
                lower[word[i]-'a']=true;
            }
        }
        int cnt=0;
        for(int i=0;i<26;i++){
            if(lower[i] && upper[i])cnt++;
        }
        
        return cnt;

    }
};