class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor)return 1;
        if(divisor==1)return dividend;
        if(dividend==INT_MIN && divisor==-1)return INT_MAX;

        bool isPositive = (dividend<0 == divisor<0); // if true then +ve answer else -ve
        unsigned int Dividend=abs(dividend);
        unsigned int Divisor=abs(divisor);
        int ans=0;
        while(Dividend>=Divisor){
            int cnt=0;
            while(Dividend>(Divisor<<(cnt+1))){
                cnt++;
            }
            ans+=1<<cnt;
            Dividend-= (Divisor<<cnt);
        }
        if(!isPositive)return -ans;
        return ans;
    }
};