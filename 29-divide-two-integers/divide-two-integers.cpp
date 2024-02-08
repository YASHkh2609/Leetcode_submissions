class Solution {
public:
    int divide(int dividend, int divisor) {
        long long ans= (long long)dividend/ (long long)divisor;
        if(ans>2147483647)return 2147483647;
        else return (int)ans; 
    }
};