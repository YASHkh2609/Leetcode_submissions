class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        vector<char>vec;
        int i=0;
        while(i<s.length()){
            if(s[i]!=')')st.push(s[i]);
            else{
                while(st.top()!='(' && !st.empty()){
                    vec.push_back(st.top());
                    st.pop();
                }
                st.pop();
                for(int i=0;i<vec.size();i++){
                    st.push(vec[i]);
                }
                vec.clear();
            }
            i++;
        }
        // cout<<;
        string ans="";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }

};