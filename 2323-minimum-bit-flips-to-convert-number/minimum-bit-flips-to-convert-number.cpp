class Solution {
public:
    int minBitFlips(int start, int goal) {
        //no. of 1s in the xor of the two nos

        int xorr = start ^ goal;
        int i=0;
        int cnt=0;
        while(xorr>0){
            if((xorr & 1))cnt++;
            xorr/=2;
            i++;
        }
        return cnt;
    }
};