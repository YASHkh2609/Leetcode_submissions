class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long expectedSum=1;
        long long sumFormed=0;
        int cnt=0;
        int m=nums.size();
        int i=0;
        while(expectedSum<=n){
            if(expectedSum<=sumFormed){
                expectedSum=sumFormed+1;
            }
            else{
                if(i<m && nums[i]<=expectedSum){
                    sumFormed+=nums[i];
                    i++;
                }
                else{
                    cnt++;
                    sumFormed+=expectedSum;
                }
            }
        }
        return cnt;
    }
};