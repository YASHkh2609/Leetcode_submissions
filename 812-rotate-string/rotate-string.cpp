class Solution {
public:
    bool rotateString(string s, string goal) {
        // string temp="";
        // int cnt=0;
        // while(cnt<s.length()){
        //     temp=s.substr(1, s.length()-1);
        //     temp+=s[0];
        //     if(temp==goal)return true;
        //     s=temp;
        //     cnt++;
        // }
        // return false;
        if(s.length()!=goal.length())return false;
        if(s.length()==0)return true;
        string copy = s+s;
        int i=0, j=0, k=0;
        while(i<copy.length() && k<goal.length()){
            if(copy[j]==goal[k]){
                j++;
                k++;
            }
            else{
                i++;
                j=i;
                k=0;
            }
        }
        if(k==goal.length())return true;
        return false;

    }
};