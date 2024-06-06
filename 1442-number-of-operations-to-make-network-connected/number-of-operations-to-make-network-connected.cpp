class DisjointSet{
public:
    vector<int>rank, parent;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<n+1;i++){
            parent[i]=i;
        }
    }
    int findUparent(int u){
        if(u==parent[u])return u;
        return parent[u]=findUparent(parent[u]);
    }

    void union_by_rank(int u, int v){
        int u_ulp=findUparent(u);
        int v_ulp=findUparent(v);

        if(u_ulp==v_ulp)return;

        if(rank[u_ulp]>rank[v_ulp]){
            parent[v_ulp]=u_ulp;
        }
        else if(rank[u_ulp]<rank[v_ulp]){
            parent[u_ulp]=v_ulp;
        }
        else{
            parent[u_ulp]=v_ulp;
            rank[v_ulp]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        //we'll traverse connections
        DisjointSet ds(n);
        int extra_edges=0;
        for(auto it:connections){
            int u=it[0];
            int v=it[1];

            if(ds.findUparent(u)!=ds.findUparent(v)){
                ds.union_by_rank(u,v);
            }
            else extra_edges++;
        }
        int nc=0;//number of components
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i)nc++;
        }
        if(extra_edges>=(nc-1)) return nc-1;
        return -1;
    }
};