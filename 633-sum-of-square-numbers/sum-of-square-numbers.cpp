class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long long i=0;i*i<=c;i++){
            int compliment = c-i*i;
            long long root = sqrt(compliment);
            if(root * root == compliment)return true;
        }
        return false;
    }
};