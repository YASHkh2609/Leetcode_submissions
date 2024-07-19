class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        int rowMinMax = INT_MIN;
        for(int i=0;i<n;i++){  
            int temp=INT_MAX;
            for(int j=0;j<m;j++){
                temp = min(temp, matrix[i][j]); 
            }
            rowMinMax=max(rowMinMax, temp);
        }
        int colMaxMin = INT_MAX;
        for(int j=0;j<m;j++){
            int temp=INT_MIN;
            for(int i=0;i<n;i++){
                temp = max(temp, matrix[i][j]); 
            }
            colMaxMin = min(colMaxMin, temp);
        }
        if(rowMinMax==colMaxMin)return {colMaxMin};
        return {};
    }
};