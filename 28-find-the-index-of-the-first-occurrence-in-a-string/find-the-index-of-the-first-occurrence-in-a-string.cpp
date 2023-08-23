class Solution {
public:
    int strStr(string str, string pat) {
        int n=str.size();
        int m=pat.size();
        int i,j=0;
        for(i=0;i<=n-m;i++){
            if(str[i]==pat[j]){
                int temp=i;
                while(str[temp]==pat[j] && j<m){
                    temp++;
                    j++;
                }
                if(j==m){
                    return temp-j;
                }
                else
                    j=0;
            }

        }
        return -1;
    }
};