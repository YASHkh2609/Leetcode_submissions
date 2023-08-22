class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int i=0;
        int m=matrix[i].size();
        int sr=0,er=n-1,sc=0,ec=m-1;
        vector<int>result;
        while(sr<=er && sc<=ec){
            for(int i=sc;i<=ec;i++){
                result.push_back(matrix[sr][i]);
            }
            sr++;

            for(int i=sr;i<=er;i++){
                result.push_back(matrix[i][ec]);
            }
            ec--;

            if(sr<=er){
                for(int i=ec;i>=sc;i--){
                result.push_back(matrix[er][i]);
                }
                er--;
            }

            if(sc<=ec){
                for(int i=er;i>=sr;i--){
                result.push_back(matrix[i][sc]);
                }
                sc++;
            }
        }
        return result;
    }
};