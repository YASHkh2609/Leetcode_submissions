class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<n;i++){
            if(ans.empty() || intervals[i][0]>ans.back()[1]){
                ans.push_back(intervals[i]);
            }
            else{
                ans.back()[1]=max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;  
        // sort(intervals.begin(),intervals.end());
        //vector<vector<int>> ans( intervals.size() , vector<int> (2));
       
        // int i=0,k=0;
        // ans[0][0]=intervals[0][0];
        // if(intervals.size()==1){
        //     ans[0][1]=intervals[0][1];
        // }
        // while(i<intervals.size()-1){
        //     while((i<intervals.size()-1) &&(intervals[i][1]<intervals[i+1][0]) ){
        //         ans[k][0]=intervals[i][0];
        //         ans[k][1]=intervals[i][1];
        //         k++;
        //         i++;
        //     }
        //     if(i==intervals.size()-1){
        //         ans[k][0]=intervals[i][0];
        //         ans[k][1]=intervals[i][1];
        //         break;
        //     }
        //     while( i<intervals.size()-1 && intervals[i][1]>=intervals[i+1][0]  ){
        //         i++;
        //     }
        //     ans[k][1]=intervals[i][1];
        //     k++;
        //     i++;
        // } 
        // vector<vector<int>>ans;
        // vector<int>row(2,0);
        // int i=0;
        // row[0]=intervals[0][0];
        // if(intervals.size()==1){
        //     row[1]=intervals[0][1];
        //     ans.push_back(row);
        // }
        // while(i<intervals.size()-1){
        //     while((i<intervals.size()-1) &&(intervals[i][1]<intervals[i+1][0]) ){
        //         row[0]=intervals[i][0];
        //         row[1]=intervals[i][1];
        //         ans.push_back(row);
        //         i++;
        //     }
        //     if(i==intervals.size()-1){
        //         row[0]=intervals[i][0];
        //         row[1]=intervals[i][1];
        //         ans.push_back(row);
        //         break;
        //     }
        //     while( i<intervals.size()-1 && intervals[i][1]>=intervals[i+1][0]  ){
        //         i++;
        //     }
        //     if(intervals[i][1]<intervals[i-1][1]){
        //         row[1]=intervals[i-1][1];
        //     }
        //     else
        //         row[1]=intervals[i][1];
        //     ans.push_back(row);
        //     i++;
        // } 
    }
};