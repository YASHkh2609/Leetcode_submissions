class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=difficulty.size();
        int m=worker.size();
        int ans=0;
        for(int i=0;i<m;i++){
            int i_profit=0;
            for(int j=0;j<n;j++){
                if(difficulty[j]<=worker[i]){
                    i_profit=max(i_profit, profit[j]);
                }
            }
            ans+=i_profit;
        }
        return ans;
    }
};