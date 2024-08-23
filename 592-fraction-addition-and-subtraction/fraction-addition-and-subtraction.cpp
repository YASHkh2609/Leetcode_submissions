class Solution {
private:
    int LCM(int a, int b){
        return (a / gcd(a, b)) * b;
    }
    int GCD(int a, int b){
        if(b==0)return a;

        return GCD(b, a%b);
    }
public:
    string fractionAddition(string expression) {
        int n=expression.length();
        vector<int>numerator;
        vector<int>denominator;

        stack<char>st;

        for(int i=0;i<n;i++){
            if(expression[i]=='/'){
                string s="";
                while(!st.empty()){
                    s= st.top()+s;
                    st.pop();
                }
                int num = stoi(s);
                numerator.push_back(num);
            }

            else if(expression[i]=='+' || (expression[i]=='-' && i!=0)){
                string s="";
                while(!st.empty()){
                    s=st.top()+s;
                    st.pop();
                }
                int num = stoi(s);
                denominator.push_back(num);
            }
            if(expression[i]!='/')
                st.push(expression[i]);
        }
        string s="";
        while(!st.empty()){
            s=st.top()+s;
            st.pop();
        }
        int num = stoi(s);
        denominator.push_back(num);

        int lcm=1;
        for(int i=0;i<denominator.size();i++){
            lcm = LCM(lcm, denominator[i]);
        }
        // cout<<lcm;
        num=0;
        for(int i=0;i<numerator.size();i++){
            numerator[i]*=(lcm/denominator[i]);
            num+=numerator[i];
            // cout<<numerator[i]<<" "<<denominator[i]<<endl;
        }
        int gcd = GCD(num, lcm);
        // cout<<gcd;
        num/=abs(gcd);
        lcm/=abs(gcd);

        string result = to_string(num)+"/"+ to_string(lcm);
        return result;

    }

};