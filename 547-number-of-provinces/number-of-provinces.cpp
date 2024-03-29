class Solution {
public:
    
    void bfs(int node, int n,vector<int>&vis,vector<vector<int>>&adj){
        queue<int>q;
        q.push(node);
        vis[node]=1;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(auto it: adj[temp]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
    }
    void dfs(int node, vector<int>&vis, vector<vector<int>>&adj){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it])dfs(it, vis, adj);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int>vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                //bfs(i, n, vis, adj);
                dfs(i, vis, adj);
                cnt++;
            }
        }
        return cnt;
    }
};