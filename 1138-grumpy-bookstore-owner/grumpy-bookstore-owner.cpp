class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size(); 
        int ans=0;
        int sum=0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0)sum+=customers[i];
        }

        for(int i=0;i<=n-minutes;i++){
            int temp_sum=0;
            for(int j=i;j<i+minutes;j++){
                if(grumpy[j]==1)temp_sum+=customers[j];
            }
            ans = max(ans, temp_sum+sum);
        }
        return ans;
    }
};