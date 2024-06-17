class Solution {
public:
    int climbStairs(int n) {
        int prev=2;
        int prev2=1;
        if(n==1)return prev2;
        int cur=0;
        for(int i=3;i<=n;i++){
            cur=prev+prev2;
            prev2=prev;
            prev=cur;
        }
        return prev;
    }
};