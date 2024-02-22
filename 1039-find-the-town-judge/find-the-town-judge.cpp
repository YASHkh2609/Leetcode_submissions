class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>arr(n+1,0), trusted(n+1,0);
        for(int i=0;i<trust.size();i++){
            arr[trust[i][0]]=1;
            trusted[trust[i][1]]++;
        }
        for(int j=1;j<n+1;j++){
            if(arr[j]==0 && trusted[j]==n-1)return j;
        }
        return -1;
    }
};