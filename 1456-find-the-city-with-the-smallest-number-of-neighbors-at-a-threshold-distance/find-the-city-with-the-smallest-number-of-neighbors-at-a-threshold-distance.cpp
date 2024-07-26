class Solution {
private:
    int dijkstra(int start,vector<int>&dist,vector<vector<pair<int, int>>>&adj,int distanceThreshold){
        priority_queue<pair<int , int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0, start});
        dist[start]=0;
        int cnt_cities=0;
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            
            pq.pop();

            for(auto it:adj[node]){
                int new_node=it.first;
                int wt=it.second;

                if((d+wt)<dist[new_node]){
                    dist[new_node]=d+wt;
                    pq.push({d+wt, new_node});
                }
            }
        }
        for(int i=0;i<dist.size();i++){
            if(i!=start){
                if(dist[i]<=distanceThreshold)cnt_cities++;
            }
        }
        return cnt_cities;
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>>adj(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        int min_city_cnt=INT_MAX;
        int min_city;
        for(int i=0;i<n;i++){
            vector<int>dist(n,INT_MAX);
            int neighbours = dijkstra(i,dist,adj,distanceThreshold);
            if(neighbours<=min_city_cnt){
                min_city_cnt=neighbours;
                min_city=i;
            }
        }
        return min_city;
    }
};