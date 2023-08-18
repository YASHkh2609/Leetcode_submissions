class Solution {
public:
    bool isPalindrome(int x) {
        int y=x;//copy of x
        if(x<0)
            return false;
        else{
            int b;
            long long int num=0;
            while(x>0){
                b=x%10;
                x/=10;
                num=num*10+b;
            }
            if(num==y){
                return true;
            }
            else
                return false;
        }
        return NULL;
    }
};