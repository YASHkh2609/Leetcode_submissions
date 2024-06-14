class Solution {
    int timer=0;
private: 
    void dfs(int src, int parent, vector<int>&vis, vector<int>&Tin, vector<int>&low,
     vector<vector<int>>&adj,  vector<vector<int>>&bridges){
        vis[src]=1;
        Tin[src]=low[src]=timer;
        timer++;

        for(auto it:adj[src]){
            if(it==parent)continue;
            if(!vis[it]){
                dfs(it, src, vis, Tin, low, adj, bridges);
                low[src]=min(low[src], low[it]);
                if(low[it]>Tin[src])bridges.push_back({src,it});
            }
            else{
                low[src]=min(low[src], low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>Tin(n, 0);
        vector<int>low(n, INT_MAX);
        vector<int>vis(n, 0);
        vector<vector<int>>bridges;

        dfs(0, -1, vis, Tin, low, adj, bridges);

        return bridges;

    }
};