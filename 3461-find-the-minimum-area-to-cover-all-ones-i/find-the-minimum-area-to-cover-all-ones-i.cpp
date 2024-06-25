class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int mincol=INT_MAX, minrow=INT_MAX, maxcol=0, maxrow=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    minrow=min(minrow, i);
                    maxrow=max(maxrow, i);
                    maxcol=max(maxcol,j);
                    mincol=min(mincol,j);
                }
            }
        }
    int length = maxrow - minrow + 1;
    int width = maxcol - mincol +1;

    return length*width;

    }
};