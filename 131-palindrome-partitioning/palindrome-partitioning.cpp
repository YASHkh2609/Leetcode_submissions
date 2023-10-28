/*class Solution {
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
};*/
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        func(0,s,path,res);
        return res;
    }

    void func(int index, string s, vector<string> &path, vector<vector<string>> &res){
        if(index == s.size()){
            res.push_back(path);
            return;
        }

        for(int i=index;i<s.size();i++){
            //Check if next indices forms a palindrome
            if(isPalindrome(s,index,i)){
                path.push_back(s.substr(index,i-index+1));
                //Check if index can be further divided into palindrome
                func(i+1,s,path,res);
                //Backtracking
                path.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s,int start,int end){
        //Checks for palindrome
        while(start <= end){
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
};