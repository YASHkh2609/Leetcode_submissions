class Solution {
public:
    string reverseWords(string s) {
        string temp="";
        string ans="";
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                while(!st.empty()){
                    temp=st.top()+temp;
                    st.pop();
                }
                if(temp!=""){
                    if(ans.length()==0)ans = temp+ans;
                    else ans =temp + " "+ans;
                }
                temp="";
            }
            else{
                st.push(s[i]);
            }
        }
        while(!st.empty()){
                temp=st.top()+temp;
                st.pop();
            }
        if(temp!=""){
            if(ans.length()==0)ans = temp+ans;
            else ans =temp + " "+ans;
        }
        return ans;
    }
};