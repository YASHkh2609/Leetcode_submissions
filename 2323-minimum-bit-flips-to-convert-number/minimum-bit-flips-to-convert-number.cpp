class Solution {
public:
    int minBitFlips(int start, int goal) {
        int orr = start|goal;
        int andd = start&goal;
        int cnt=0;
        while(orr!=0 || andd!=0){
            if( (orr&1) != (andd&1)){
                cnt++;
                // cout<<orr<<" "<<andd<< " ";
                // cout<< cnt<<endl;
            }
            orr=orr>>1;
            andd=andd>>1;
        }
        return cnt;
    }
};