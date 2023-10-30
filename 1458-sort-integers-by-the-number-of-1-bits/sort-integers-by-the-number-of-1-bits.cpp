class Solution {
public:
    static int findWeight(int num){
        int weight=0;//hamming weight-->number of set bits
        int mask=1;

        while(num>0){
            if((num & mask)){
                weight++;
                num=num^mask;//so that we wont have to loop 31 times everytime
            }
            mask=mask<<1;
        }
        return weight;
    }
    static bool compare(int a, int b){
        if(findWeight(a)==findWeight(b))return a<b;
        return findWeight(a)<findWeight(b);
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),compare);
        return arr;
    }
};