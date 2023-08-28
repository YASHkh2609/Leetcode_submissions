class Solution {
public:
    bool rotateString(string s, string goal) {
        // int i=0;
        // int j=0;
        // string ans=s+s;
        // while(ans.size()-i>goal.size()-j){
        //     int temp=i;
        //     while(ans[temp]==goal[j] && j<goal.size()){
        //         temp++;
        //         j++;
        //     }
        //     if(j==goal.size() && s.size()==goal.size()){
        //         return true;
        //     }
        //     else
        //         j=0;
        //     i++;
        // }
        // return false;
        if(s.size()!=goal.size()) return false;

        string concatenate = s+s;
        if(concatenate.find(goal)!= string::npos){
            return true;
        }
        else return false;
    }
};