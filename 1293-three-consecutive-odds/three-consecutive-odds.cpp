class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int i=0;
        int j=0;
        int cnt=0;
        while(j<arr.size()){
            if(arr[j]%2!=0){
                cnt++;
                if(cnt==3)return true;
            }
            else{
                cnt=0;
                i=j;
            }
            j++;
        }
        return false;
    }
};