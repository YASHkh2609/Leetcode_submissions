class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        //sum of obs to be divisible by n+m
        int totalSum = mean*(n+m);
        int mSum=0;
        for(int i=0;i<m;i++){
            mSum+=rolls[i];
        }
        int nSum = totalSum-mSum;
        if(nSum> 6*n || nSum<n)return {};

        vector<int>missingValues(n, 1);
        int remainingSum=nSum- n;
        for(int i=0;i<n;i++){
            if(remainingSum>5){
                missingValues[i]+=5;
                remainingSum-=5;
            }
            else{
                missingValues[i]+=remainingSum;
                break;
            }
        }
        return missingValues;
    }
};