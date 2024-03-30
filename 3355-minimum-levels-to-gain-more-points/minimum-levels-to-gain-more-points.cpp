class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        vector<int>sum_array(possible.size(),0);
        for(int i=0;i<possible.size();i++){
            if(possible[i]==1){
                if(i==0){
                    sum_array[0]=1;
                }
                else{
                    sum_array[i]=sum_array[i-1]+1;
                }
            }
            else{
                if(i==0){
                    sum_array[0]=-1;
                }
                else{
                    sum_array[i]=sum_array[i-1]-1;
                }
            }
        }
        int dc , b;
        int level=0;
        for(int i=0;i<sum_array.size();i++){
            dc=sum_array[i];
            b=sum_array[sum_array.size()-1]-dc;
            if(dc>b){
                level=i+1;
                break;
            }
        }
        if(level==0 || level==sum_array.size())return -1;
        return level;
    }
};