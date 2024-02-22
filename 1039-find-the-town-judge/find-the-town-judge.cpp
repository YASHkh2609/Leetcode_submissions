class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<bool>arr(n+1,0);
        for(int i=0;i<trust.size();i++){
            arr[trust[i][0]]=1;
        }
        int town_judge=-1;
        for(int j=1;j<n+1;j++){
            if(arr[j]==0)town_judge=j;
        }
        int cnt=0;
        for(int k=0;k<trust.size();k++){
            if(trust[k][1]==town_judge)cnt++;
        }
        if(cnt==n-1){
            return town_judge;
        }
        return -1;
    }
};