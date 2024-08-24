class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int maxi=0;
        for(int i=0;i<houses.size();i++){
            int mini=INT_MAX;
            for(int j=0;j<heaters.size();j++){
                mini = min(mini,abs(houses[i]-heaters[j]));
            }
            maxi = max(mini, maxi);
        }
        return maxi;
    }
};