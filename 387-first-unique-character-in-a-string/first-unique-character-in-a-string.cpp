class Solution {
public:
    int firstUniqChar(string s) {
        map<int, int>mpp;
        for(int i=0;i<s.length();i++){
            mpp[(int)s[i]]++;
        }
        for(int i=0;i<s.length();i++){
            if(mpp[(int)s[i]]==1){
                return i;
            }

        }
        return -1;

    }
};