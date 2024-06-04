class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int>mpp;
        for(int i=0;i<s.length();i++){
            mpp[s[i]]++;
        }   
        int even=0, odd=0, cnt_odd=0;
        for(auto it:mpp){
            if(it.second%2==0)even+=it.second;
            else{
                cnt_odd++;
                odd+=it.second;
            }
        }
        if(cnt_odd==0)return even;
        return even+odd-cnt_odd+1;
    }
};