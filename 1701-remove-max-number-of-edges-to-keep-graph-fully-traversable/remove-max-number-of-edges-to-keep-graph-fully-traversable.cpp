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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet dsAlice(n);
        DisjointSet dsBob(n);

        int used_edges=0;
        for(auto it:edges){
            int type=it[0];
            int u=it[1];
            int v=it[2];

            if(type == 3 && (dsAlice.findUparent(u)!=dsAlice.findUparent(v))){
                dsAlice.union_by_rank(u,v);
                used_edges++;
            }

            if(type == 3 && (dsBob.findUparent(u)!=dsBob.findUparent(v))){
                dsBob.union_by_rank(u,v);
            }
        }

        int nc=0;//number of components
        for(int i=1;i<n+1;i++){
            if(dsAlice.parent[i]==i)nc++;
        }
        if(nc==1)return edges.size() - used_edges;

        //handle type1
        int t1_used_edges=0;
        for(auto it:edges){
            int type=it[0];
            int u=it[1];
            int v=it[2];

            if(type == 1 && (dsAlice.findUparent(u)!=dsAlice.findUparent(v))){
                dsAlice.union_by_rank(u,v);
                t1_used_edges++;
            }
        }
        //handle type2

        int t2_used_edges=0;
        for(auto it:edges){
            int type=it[0];
            int u=it[1];
            int v=it[2];

            if(type == 2 && (dsBob.findUparent(u)!=dsBob.findUparent(v))){
                dsBob.union_by_rank(u,v);
                t2_used_edges++;
            }
        }

        int nc_t1=0, nc_t2=0;//number of components
        for(int i=1;i<n+1;i++){
            if(dsAlice.parent[i]==i)nc_t1++;
            if(dsBob.parent[i]==i)nc_t2++;
        }

        if(nc_t1==1 && nc_t2==1)return edges.size() - (used_edges+t2_used_edges+t1_used_edges);

        return -1;

    }
};