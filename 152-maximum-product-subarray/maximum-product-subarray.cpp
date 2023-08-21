#include<bits/stdc++.h>
#include<climits>
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int curprod=1;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            curprod*=nums[i];
            ans=max(ans,curprod);
            if(curprod==0){
                curprod=1;
            }
        }
        curprod=1;
        for(int i=n-1;i>=0;i--){
            curprod*=nums[i];
            ans=max(ans,curprod);
            if(curprod==0){
                curprod=1;
            }
        }
        return ans;
    }
};