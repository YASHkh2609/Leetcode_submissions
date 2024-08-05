class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //we need to identify a same sized string in s2 with the same freq of characters
        //let us get freq for s1
        //consider a window of s1 size and just traverse s2 to check if freq is same as s1
        if(s2.length()<s1.length())return false;
        vector<int>freq_s1(26,0);
        vector<int>freq_s2(26,0);
        for(int i=0;i<s1.length();i++){
            freq_s1[s1[i]-'a']++;
        }

        int k=s1.length();
        int windowSize=0;
        int i=0,j=0;
        while(j<s2.length()){
            while(windowSize<k){
                freq_s2[s2[j]-'a']++;
                j++;
                windowSize++;
            }
            if(freq_s1==freq_s2)return true;
            freq_s2[s2[i]-'a']--;
            i++;
            windowSize--;
        }
        return false;
    }
};