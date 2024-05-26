class Solution {
public:
    string compressedString(string word) {
        int cnt=1;
        string st="";
        bool flag=false;
        int i;
        for(i=0;i<word.length()-1;i++){
            if(word[i]==word[i+1]){
                cnt++;
                flag=true;
            }
            else{
                flag=false;
            }
            if((i==word.length()-2 && flag==true) || flag==false){
                int num=cnt/9;
                for(int j=0;j<num;j++){
                    st+='9';
                    st+=word[i];
                }
                if(cnt%9!=0){
                    st+=to_string(cnt%9);
                    st+=word[i];
                }
                cnt=1;
            }
        }
        if(!flag){
            st+='1';
            st+=word[i];
        }
        return st;
        
    }
};