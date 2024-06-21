class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size(); 
        int sum=0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0)sum+=customers[i];
        }
        int i=0;
        int j=0;
        int tempsum=0;
        int maxsum=0;
        int cnt=0;
        while(j<n){
            if(cnt<minutes){
                if(grumpy[j]==1)tempsum+=customers[j];
                cnt++;
                j++;
            }
            else {
                cnt--;
                maxsum = max(maxsum, tempsum);
                if(grumpy[i]==1)tempsum-=customers[i];
                i++;
            }
        }
        maxsum = max(maxsum, tempsum);
        return maxsum+sum;
    }
};