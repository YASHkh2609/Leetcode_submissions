class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum=0;
        for(int i=0;i<chalk.size();i++){
            sum+=chalk[i];
        }
        long long remaining = k%sum;
        int i=0;
        while(remaining>=chalk[i]){
            remaining-=chalk[i];
            i++;
        }
        return i;
    }
};