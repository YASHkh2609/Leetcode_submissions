class Solution {
public:
    int p=1e9 + 7;
    long long modular_exponentiation(long long num, long long x){
        // if(num<0) nums1=-1*num;
        //x-->power,num-->number 
        long long ans=1;
        num=num%p;
        if(num==0)return 0;
        while(x>0){
            if(x%2==0){
                num=(num*num)%p;
                x/=2;
            }
            else{
                ans=(num*ans)%p;
                x--;
            }
        }
        return ans;  
    }
    int countGoodNumbers(long long n) {
        long long count_4=n/2;
        long long count_5=n-count_4;
        long long res=((modular_exponentiation((long long)5, count_5)%p * modular_exponentiation((long long)4,count_4)%p)%p);
        return (int)res;
    }
};