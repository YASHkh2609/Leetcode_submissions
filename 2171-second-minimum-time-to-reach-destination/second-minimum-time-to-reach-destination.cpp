class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>>adj(n+1);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<pair<int , int>>q;
        vector<vector<int>>dist(n+1,vector<int>(2, INT_MAX));

        q.push({1, 0});
        dist[1][0]=0;

        while(!q.empty()){
            int node=q.front().first;
            int d=q.front().second;
            q.pop();
            int new_dist=0;
            int signal = d/change; //to see if signal green or red
            if(signal %2==0){//green
                new_dist= d+time;
            }
            else{//red
                int waitTime=change - d%change;
                new_dist = d+waitTime+time;
            }

            for(auto it:adj[node]){
                if(dist[it][0]==INT_MAX){//first visit
                    q.push({it, new_dist});
                    dist[it][0]=new_dist;
                }
                else if(dist[it][1]==INT_MAX && new_dist>dist[it][0]){//second visit
                    q.push({it, new_dist});
                    dist[it][1]=new_dist;
                }
            }
        }
        return dist[n][1];
    }
};