class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++){
            int j=0;
            int k=n-1;
            while(j<k){
                swap(matrix[j][i],matrix[k][i]);
                j++;
                k--;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i>j){
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
        }

    }
};