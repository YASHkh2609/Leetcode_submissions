class Solution {
public:
    int minBitFlips(int start, int goal) {
        // int orr = start|goal;
        // int andd = start&goal;
        int cnt=0;
        // while(orr!=0 || andd!=0){
        //     if( (orr&1) != (andd&1)){
        //         cnt++;
        //         // cout<<orr<<" "<<andd<< " ";
        //         // cout<< cnt<<endl;
        //     }
        //     orr=orr>>1;
        //     andd=andd>>1;
        // }
        int xorr= start ^ goal; // xor will set only the bits which are flipped
        //now we can count the set bits
        while(xorr!=0){
            if((xorr&1)==1)cnt++;
            xorr=xorr>>1;
        }

        return cnt;
    }
};