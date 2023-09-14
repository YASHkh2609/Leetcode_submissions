class Solution {
public:
    int reverse(int x) {
        long long ans=0;
        int temp=x;
        while(abs(x)>0){
            ans=ans*10+x%10;
            x/=10;
        }
        if(ans<INT_MIN || ans>INT_MAX)
            return 0;
        else    
            return ans;
    }
};