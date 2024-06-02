class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        //[[1,5][5,9][9,10]]--> 
        sort(meetings.begin(), meetings.end());
        int begin=meetings[0][0];
        int end=meetings[0][1];
        int j=0;
        int busydays=0;
        for(j;j<meetings.size()-1;j++){
            if(meetings[j][1]<meetings[j+1][0]){
                end=max(end,meetings[j][1]);
                busydays+=end-begin+1;
                begin=max(end+1, meetings[j+1][0]);
            }
            else if(meetings[j][1]>=meetings[j+1][1]){
                end=max(end, meetings[j][1]);
            }
            else{
                end=max(end, meetings[j+1][1]);
            }
        }
        end=max(end, meetings[j][1]);
        busydays+=end-begin+1;
        return days-busydays;
        
    }
};