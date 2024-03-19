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
            if((row-1)>=0 && !vis[row-1][col] && image[row-1][col]==og_color){
                vis[row-1][col]=1;
                q.push({row-1,col});
                image[row-1][col]=color;
            }
            if((row+1)<m && !vis[row+1][col] && image[row+1][col]==og_color){
                vis[row+1][col]=1;
                q.push({row+1,col});
                image[row+1][col]=color;
            }
            if((col-1)>=0 && !vis[row][col-1] && image[row][col-1]==og_color){
                vis[row][col-1]=1;
                q.push({row,col-1});
                image[row][col-1]=color;
            }
            if((col+1)<n && !vis[row][col+1] && image[row][col+1]==og_color){
                vis[row][col+1]=1;
                q.push({row,col+1});
                image[row][col+1]=color;
            }
        }
        return image;
    }
};