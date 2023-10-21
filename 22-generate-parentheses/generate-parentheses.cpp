class Solution {
public:
    vector<string>ans;
    void give_parenthesis(int n, int i, int o, int c, char arr[]){
        if(i==2*n){
            string str="";
            for(int j=0;j<i;j++){
                str+=arr[j];
            }
            ans.push_back(str);
            return;
            
        }
        if(o<n){
            arr[i]='(';
            give_parenthesis(n, i+1, o+1, c, arr);
        }
        if(o>c){
            arr[i]=')';
            give_parenthesis(n,i+1,o,c+1,arr);
        }

    }
    vector<string> generateParenthesis(int n) {
        char arr[2*n];
        give_parenthesis(n,0,0,0,arr);
        return ans;
    }
};