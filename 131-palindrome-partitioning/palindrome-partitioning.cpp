class Solution {
public:
    bool isPalindrome(int j, int k, string str){
        while(j<=k){
            if(str[j]!=str[k])return false;
            j++;
            k--;
        }
        return true;
    }
    void doPartition(string s,int ind,vector<string>&ds, vector<vector<string>>&ans ){
        if(ind==s.length()){
            ans.push_back(ds);
            return;
        }

        for(int i=ind;i<s.length();i++){
            if(isPalindrome(ind,i,s)){
                ds.push_back(s.substr(ind,i-ind+1));
                doPartition(s,i+1,ds,ans);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>ds;
        vector<vector<string>>ans;
        doPartition(s,0,ds,ans);
        return ans;
    }
};