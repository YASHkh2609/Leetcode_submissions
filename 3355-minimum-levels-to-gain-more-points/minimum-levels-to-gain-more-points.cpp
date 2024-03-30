class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int sum=0;
        for(int i=0;i<possible.size();i++){
            if(possible[i]==1)sum+=1;
            else sum+=-1;
        }

        int dc=0, b=0;

        for(int i=0;i<possible.size()-1;i++){//bob has to play atleast one level
            if(possible[i]==1)dc+=1;
            else dc+=-1;

            b=sum-dc;
            if(dc>b)return i+1;
        }
        return -1;
    }
};