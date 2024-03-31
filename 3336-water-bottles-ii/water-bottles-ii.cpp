class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans;
        int empty=numBottles;
        ans=empty;
        while(empty>=numExchange){
            numBottles=0;
            while(empty>=numExchange){
                empty-=numExchange;
                ans++;
                numExchange++;
                numBottles++;
            }
            empty+=numBottles;
        }
        return ans;
    }
};