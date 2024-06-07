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
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int row1=stones[i][0], col1=stones[i][1];
                int row2=stones[j][0], col2=stones[j][1];

                if(row1 == row2 || col1 == col2){
                    ds.union_by_rank(i,j);
                }
            }
        }
        int nc=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i)nc++;
        }
        return n-nc;
    }
};