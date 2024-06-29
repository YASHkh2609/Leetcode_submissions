class Solution {
private: 
    void ancestorsUsingDFS(int start, int node, vector<vector<int>>&ancestors,vector<int>&vis, vector<vector<int>>&adj){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                ancestors[it].push_back(start);
                ancestorsUsingDFS(start, it, ancestors, vis, adj);
            }
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        //using dfs with each vertex and assign start as parent for each visited node

        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
        }

        vector<vector<int>>ancestors(n);
        for(int i=0;i<n;i++){
            vector<int>vis(n, 0);
            ancestorsUsingDFS(i,i, ancestors, vis, adj);
        }
        return ancestors;
    }
};