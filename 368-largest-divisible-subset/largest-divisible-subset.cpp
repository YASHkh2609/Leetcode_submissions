/*class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<vector<int>> PossiblePairs;
        vector<int>empty;
        if(nums.size()==1)return nums;
        sort(nums.begin(),nums.end());
        bool isempty = true;
        for(int i=0;i<nums.size()-1;i++){
            vector<int>intermediate;
            intermediate.push_back(nums[i]);
            PossiblePairs.push_back(intermediate);
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]%nums[i]==0){
                    // int flag=0;
                    for(int k=0;k<PossiblePairs.size();k++){
                        if(PossiblePairs[k].back()==nums[i]){
                            PossiblePairs[k].push_back(nums[j]);
                            // flag=1;
                            break;
                        }
                    }
                    // if(flag==0){
                    //     intermediate.push_back(nums[j]);
                    //     PossiblePairs.push_back(intermediate);
                    // }
                    isempty=false;
                    break;
                }
            }
        }
        int sizemax=0;
        for(int i=0;i<PossiblePairs.size();i++){
            if(PossiblePairs[i].size()>PossiblePairs[sizemax].size()){
                sizemax=i;
            }
        }
        return PossiblePairs[sizemax];
    }
};*/
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size(), maxi=1, num=-1;
        vector<int>v;
        sort(nums.begin(), nums.end());
        vector<int>dp(n, 1);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(!(nums[i]%nums[j]) && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    if(maxi<dp[i]){
                        maxi=dp[i];
                    }
                }
            }
        }
        for(int i=n-1; i>=0; i--){
            if(maxi==dp[i] && (num==-1 || !(num%nums[i]))){
                v.push_back(nums[i]);
                maxi--;
                num=nums[i];
            }
        }
        return v;
    }
};