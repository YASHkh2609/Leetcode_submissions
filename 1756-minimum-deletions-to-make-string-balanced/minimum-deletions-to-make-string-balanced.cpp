class Solution {
public:
    int minimumDeletions(string s) {
        int cnt_a=0, cnt_b=0;
        int n=s.length();
        for(int i=1;i<n;i++){ //getting b's towards left and a's towards right of index=0
            if(s[i]=='a')cnt_a++;
        }
        int min_deletions=INT_MAX;
        for(int k=0;k<n;k++){
            if(k!=0){
                if(s[k-1]=='b')cnt_b++;
                if(s[k]=='a')cnt_a--;
            }
            min_deletions = min(min_deletions, cnt_a+cnt_b);
        }
        return min_deletions;
    }
};