class Solution {
public:
    bool dfs_check(int src,vector<vector<int>>& graph, vector<int>&coloured, int colour){
        coloured[src]=colour;
        for(int i=0;i<graph[src].size();i++){
            if(coloured[graph[src][i]]==-1){
                if(dfs_check(graph[src][i], graph, coloured, !coloured[src])==false)return false;
            }
            else{
                if(coloured[graph[src][i]] == coloured[src])return false;
            }
        }
        return true;
    }
    bool bfs_check(int src,vector<vector<int>>& graph,vector<int>&coloured) {
        queue<int>q;
        q.push(src);
        
        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(int i=0;i<graph[node].size();i++){
                if(coloured[graph[node][i]]==-1){
                    q.push(graph[node][i]);
                    coloured[graph[node][i]]=!coloured[node];
                }
                else{
                    if(coloured[graph[node][i]]==coloured[node])return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph){
        int n=graph.size();
        vector<int>coloured(n,-1);
        for(int i=0;i<n;i++){// we have to consider that graph might have components
            if(coloured[i]==-1){
                //if(!bfs_check(i, graph, coloured))return false;//if any one component is not bipartite graph is not bipartite
                if(!dfs_check(i,graph, coloured, 0))return false;
            }
        }
        return true;
    }
};