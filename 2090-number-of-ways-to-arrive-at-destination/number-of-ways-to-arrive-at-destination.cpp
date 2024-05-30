class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long,long long>>>adj(n);
        for(auto it:roads){
            long long u=it[0];
            long long v=it[1];
            long long wt=it[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u, wt});
        }
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>>pq;
        vector<long long>dist(n, LLONG_MAX);
        dist[0]=0;
        pq.push({0, 0});//{time, node} dist will represent cost/time
        vector<long long>ways(n, 0);
        ways[0]=1;
        int mod=(int)(1e9+7);
        while(!pq.empty()){
            long long d =pq.top().first;
            long long node=pq.top().second;
            
            pq.pop();
            for(auto it: adj[node]){
                long long new_node=it.first;
                long long wt=it.second;
                
                if((d+wt)<dist[new_node]){
                    dist[new_node]=d+wt;
                    pq.push({(d+wt), new_node});
                    ways[new_node]=ways[node];
                }
                else if((d+wt)==dist[new_node]){
                    ways[new_node]=(ways[new_node]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};