class Solution {
public:
    int pivotInteger(int n) {
        vector<int> lr(n+1,0), rl(n+1,0);
        for(int i=1;i<=n;i++){
            if(i==1)lr[i]=i;
            else if(i>1)lr[i]=lr[i-1]+i;

            if(n-i+1==n)rl[n-i+1]=n-i+1;
            else if(n-i+1<n)rl[n-i+1]=n-i+1 + rl[n-i+2];
        }
        for(int i=1;i<=n;i++){
            if(lr[i]==rl[i])return i;
        }
        return -1;
    }
};