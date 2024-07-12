class Solution {
private: 
    int helper(string s, int reward1, int reward2, char c, char d){
        int i=0;
        int reward=0;
        stack<char>st;
        while(i<s.length()){
            if(s[i]==d && (st.empty()==false) &&st.top()==c ){
                reward+=reward1;
                st.pop();
            }
            else st.push(s[i]);
            i++;
        }
        string rem="";
        while(!st.empty()){
            rem+=st.top();
            // cout<<st.top();
            st.pop();
        }
        reverse(rem.begin(), rem.end());
        i=0;
        while(i<rem.length()){
            if(rem[i]==c && (st.empty()==false) && st.top()==d){
                reward+=reward2;
                st.pop();
            }
            else st.push(rem[i]);
            i++;
        }
        return reward;
    }
public:
    int maximumGain(string s, int x, int y) {
        if(x>=y){
            return helper(s, x, y, 'a', 'b');
        }
        return helper(s, y, x, 'b', 'a');
    }
};