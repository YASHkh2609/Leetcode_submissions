class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        //Using Dijkstra's Algo
        if(grid[0][0]==1)return -1;
        int n=grid.size();
        priority_queue<pair<int,pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int, int>>>>pq;
        vector<vector<int>>dist(n, vector<int>(n, 1e9));
        dist[0][0]=0;
        pq.push({0,{0,0}});

        int delrow[]={0,-1,-1,-1,0,1,1,1};
        int delcol[]={1,1,0,-1,-1,-1,0,1};

        while(!pq.empty()){
            int d=pq.top().first;
            int row=pq.top().second.first;
            int col= pq.top().second.second;
            pq.pop();

            for(int i=0;i<8;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==0 && 
                (d+1)< dist[nrow][ncol]){
                    dist[nrow][ncol]=d+1;
                    pq.push({dist[nrow][ncol], {nrow, ncol}});
                }
            }
        }
        if(dist[n-1][n-1]==1e9)return -1;
        return (dist[n-1][n-1]+1);
    }
};