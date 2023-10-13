class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long num1=n;
        if(n<0)num1=-1*num1;
            while(num1){
            if(num1%2==0)
            {
                x*=x;
                num1/=2;
            }    
            else{
                ans=ans*x;
                num1-=1;
            }
        }
        if(n<0) ans=(double)(1.0)/(double)(ans);
        return ans;
    }   
};