class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        vector<vector<int>>vis(m, vector<int>(n,0));

        queue<pair<int, int>>q;
        vis[sr][sc]=1;
        q.push({sr,sc});
        int og_color= image[sr][sc];
        image[sr][sc]=color;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            int delrow[]={-1,0,1,0};
            int delcol[]={0,-1,0,1};
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && 
                !vis[nrow][ncol] && image[nrow][ncol]==og_color){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                    image[nrow][ncol]=color;
                }
            }
        }
        return image;
    }
};