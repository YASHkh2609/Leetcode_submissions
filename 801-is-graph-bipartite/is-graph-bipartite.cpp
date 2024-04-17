class Solution {
public:
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
        for(int i=0;i<n;i++){
            if(coloured[i]==-1){
                coloured[i]=0;
                if(!bfs_check(i, graph, coloured))return false;
            }
        }
        return true;
    }
};