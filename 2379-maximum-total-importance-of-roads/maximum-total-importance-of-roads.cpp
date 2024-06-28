class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>vec(n, 0);
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            vec[u]++;
            vec[v]++;
        }
        sort(vec.begin(),vec.end());
        long long ans=0;
        long long multiplier = 1;
        for(auto it:vec){
            ans+= it*multiplier;
            multiplier++;
        }
        return ans;
    }
};