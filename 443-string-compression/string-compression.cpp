class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0,j=1;
        int ansIndex=0;
        int cnt=1;
        while(i<chars.size()){ 
            if(j<chars.size() && chars[i]==chars[j]){
                cnt++;
                j++;
            }
            else{
                if(cnt==1){
                    chars[ansIndex++] = chars[i];
                }
                else{
                    chars[ansIndex++]=chars[i];
                    string count = to_string(cnt);
                    for(char ch: count){
                        chars[ansIndex++]=ch;
                    }
                }
                i=j;
                j++;
                cnt=1;
            }
        }
        return ansIndex;
    }
};