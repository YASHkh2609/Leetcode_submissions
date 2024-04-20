class Solution {
public:
    bool dfs(int src,vector<vector<int>>&graph, vector<int>&vis, vector<int>&pathvis){
        vis[src]=1;
        pathvis[src]=1;

        for(auto it: graph[src]){
            if(!vis[it]){
                if(dfs(it, graph, vis, pathvis)) return true;
            }
            else{
                if(pathvis[it])return true;
            }
        }
        pathvis[src]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>safe_nodes;
        int n=graph.size();
        vector<int>vis(n,0);
        vector<int>pathvis(n,0);
        for(int i=0;i<n;i++){
            if(!dfs(i, graph, vis, pathvis))safe_nodes.push_back(i);
        }
        return safe_nodes;
    }
};