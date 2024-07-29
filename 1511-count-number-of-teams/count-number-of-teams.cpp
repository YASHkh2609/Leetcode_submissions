class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n=rating.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(rating[j]>rating[i]){
                    for(int k=j+1;k<n;k++){
                        if(rating[k]>rating[j])cnt++;
                    }
                }
                else if(rating[j]<rating[i]){
                    for(int k=j+1;k<n;k++){
                        if(rating[k]<rating[j])cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};