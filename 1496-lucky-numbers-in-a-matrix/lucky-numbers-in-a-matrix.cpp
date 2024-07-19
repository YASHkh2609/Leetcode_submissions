class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int num = matrix[i][j];

                int mini = num;
                int maxi = num;

                for(int k=0;k<m;k++){
                    mini = min(mini, matrix[i][k]);
                }
                for(int k=0;k<n;k++){
                    maxi=max(maxi, matrix[k][j]);
                }

                if(maxi == num && mini == num){
                    ans.push_back(num);
                }
            }
        }
        return ans;
    }
};