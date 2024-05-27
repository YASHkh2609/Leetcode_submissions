class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>>adj(n);
        for(auto it:flights){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
        }
        //dist==price
        vector<int>dist(n, INT_MAX);
        //priority_queue<pair<int,pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int, int>>>>pq;
        //element in pq--> {dist,{node, path length}}
        queue<pair<int, pair<int, int>>>pq;
        pq.push({0,{src, 1}});
        dist[src]=0;
        while(!pq.empty()){
            int d=pq.front().first;
            int node=pq.front().second.first;
            int len=pq.front().second.second;
            pq.pop();

            // if(node==dst)return dist[node];

            for(auto it: adj[node]){
                int new_node=it.first;
                int wt=it.second;

                if((d+wt)<dist[new_node] && (len+1) <= (2+k)){
                    dist[new_node]=d+wt;
                    pq.push({d+wt,{new_node, len+1}});
                }
            }
        }
        int ans=-1;
        if(dist[dst]!=INT_MAX)ans=dist[dst];
        return ans;
    }
};