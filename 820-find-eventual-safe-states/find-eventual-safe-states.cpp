class Solution {
public:
    bool dfs(int src,vector<vector<int>>&graph, vector<int>&vis, vector<int>&pathvis, vector<bool>&safe_nodes){
        vis[src]=1;
        pathvis[src]=1;

        for(auto it: graph[src]){
            if(!vis[it]){
                if(dfs(it, graph, vis, pathvis, safe_nodes)){
                    safe_nodes[it]=0;
                    return true;
                }

            }
            else{
                if(pathvis[it]){
                    safe_nodes[it]=0;
                    return true;
                }
            }
        }
        safe_nodes[src]=1;
        pathvis[src]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        // vector<bool>safe_nodes(n,0);
        // vector<int>ans;
        // vector<int>vis(n,0);
        // vector<int>pathvis(n,0);

        // for(int i=0;i<n;i++){
        //     int check = dfs(i, graph, vis, pathvis, safe_nodes);
        // }
        // for(int i=0;i<n;i++){
        //     if(safe_nodes[i]==1){
        //         ans.push_back(i);
        //     }
        // }
        // return ans;

        //using TOPO sort on reversed graph

        //reverse the graph
        vector<vector<int>>reversed_g(n);
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                reversed_g[it].push_back(i);
            }
        }
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto it: reversed_g[i]){
                indegree[it]++;
            }
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)q.push(i);
        }
        vector<int>safe_nodes;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            safe_nodes.push_back(node);

            for(auto it: reversed_g[node]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        sort(safe_nodes.begin(), safe_nodes.end());
        return safe_nodes;
    }
};