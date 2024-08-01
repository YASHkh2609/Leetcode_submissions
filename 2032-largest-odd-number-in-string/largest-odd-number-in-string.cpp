class Solution {
public:
    string largestOddNumber(string num) {
        string ans="";
        for(int i=num.size()-1;i>=0;i--){
            char c=num[i];
            int c_to_int=c-'0';
            if(c_to_int&2!=0){
                ans=num.substr(0, i+1);
                return ans;
            }
        }
        return ans;
    }
};