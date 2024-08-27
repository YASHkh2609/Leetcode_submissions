class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>>adj(n); //u->{v,wt},...

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double wt=succProb[i];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        vector<double>prob(n, 0);

        priority_queue<pair<double, int>>pq;
        pq.push({1,start_node});
        prob[start_node]=1;

        while(!pq.empty()){
            int node=pq.top().second;
            double p=pq.top().first;

            pq.pop();

            for(auto it:adj[node]){
                int new_node=it.first;
                double new_p=it.second;

                if(new_p*p>prob[new_node]){
                    pq.push({new_p*p,new_node});
                    prob[new_node]=new_p*p;
                }
            }
        }
        for(auto it:prob){
            cout<<it<<endl;
        }
        return prob[end_node];


    }
};