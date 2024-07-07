class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int cnt=0;
        int emptied=0;
        while(numBottles>0){
            cnt+=numBottles;
            emptied+=numBottles;
            numBottles = emptied/numExchange;
            emptied = emptied%numExchange;
        }
        return cnt;
    }
};