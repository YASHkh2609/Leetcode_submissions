class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int total_time = 0;
        double waitTime = 0;
        int n = customers.size();
        for(int i=0;i<n;i++){
            total_time = max(total_time, customers[i][0]);
            total_time+=customers[i][1];
            cout<<total_time;
            waitTime= waitTime + (total_time - customers[i][0]);
            cout<<waitTime<<endl;
        }
        return (waitTime)/n ;
    }
};