class DisjointSet{
public:
    vector<int>size, parent;
    DisjointSet(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0;i<n+1;i++){
            parent[i]=i;
        }
    }
    int findUparent(int u){
        if(u==parent[u]){
            return u;
        }
        return parent[u]=findUparent(parent[u]);
    }
    void union_by_size(int u, int v){
        int u_ulp=findUparent(u);
        int v_ulp=findUparent(v);

        if(u_ulp==v_ulp)return;
        if(size[u_ulp]>size[v_ulp]){
            parent[v_ulp]=u_ulp;
            size[u_ulp]+=size[v_ulp];
        }
        else{
            parent[u_ulp]=v_ulp;
            size[v_ulp]+=size[u_ulp];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        int delrow[]={0,-1,0,1};
        int delcol[]={1,0,-1,0};
        vector<pair<int, int>>zero_occ;
        for(int i=0;i<n;i++){//traverse to create a disjoint set
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    for(int k=0;k<4;k++){
                        int nrow=i+delrow[k];
                        int ncol=j+delcol[k];
                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<n &&grid[nrow][ncol]==1&& 
                        ds.findUparent(i*n+j)!=ds.findUparent(nrow*n+ncol)){
                            ds.union_by_size(i*n+j, nrow*n+ncol);
                        }
                    }
                }
                else{
                    zero_occ.push_back({i,j});//storing the occurrences of 0
                }
            }
        }
        int max_size=0;
        for(int i=0;i<n*n;i++){
            max_size=max(max_size, ds.size[i]);//get max size in base situation
        }
        //cout<<max_size<<endl;
        for(auto it:zero_occ){ //traverse the '0's occurrences
            int row=it.first;
            int col=it.second;
            set<int>Uparent;//to store ultimate parents of neighbours
            for(int k=0;k<4;k++){
                int nrow=row+delrow[k];
                int ncol=col+delcol[k];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && 
                grid[nrow][ncol]==1){
                    Uparent.insert(ds.findUparent(nrow*n+ncol));
                }
            }
            int cur_size=1;
            for(auto it:Uparent){
                cur_size+=ds.size[it];
            }
            max_size=max(max_size, cur_size);
            //cout<<max_size<<endl;
        }
        return max_size;
    }
};