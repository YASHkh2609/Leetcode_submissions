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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, int>mpp;
        DisjointSet ds(accounts.size());
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mpp.find(accounts[i][j])==mpp.end()){//msil doesn't exist in map
                    mpp[accounts[i][j]]=i;
                }
                else{//exists in map ==> same component ==>union
                    ds.union_by_rank(mpp.find(accounts[i][j])->second,i);
                }
            }
        }
        map<int, vector<string>>p2mail;
        for(auto it:mpp){
            int Uparent=ds.findUparent(it.second);
            p2mail[Uparent].push_back(it.first);
        }
        vector<vector<string>>ans;
        for(auto it:p2mail){
            string name=accounts[it.first][0];
            sort(it.second.begin(), it.second.end());
            it.second.insert(it.second.begin(), name);
            ans.push_back(it.second);
        }
        return ans;
    }
};