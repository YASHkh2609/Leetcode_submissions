
#include<bits/stdc++.h>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        /*vector<int>nums1;
        for(int k=0;k<nums.size();k++){
            nums1.push_back(nums[k]);
        }
        sort(nums.begin(),nums.end());
        int i=0;
        int j=n-1;
        vector<int> result;
        int sum=0;
        while(i<j){
            sum=nums[i]+nums[j];
            if(sum<target){
                i++;
            }
            else if(sum>target){
                j--;
            }
            else{
                int left=binarySearch(nums1,0,n-1,nums[i]);
                int right=binarySearch(nums1,0,n-1,nums[j]);
                result.push_back(left);
                result.push_back(right);
                i++;
                j--;
                return result;
            }
        }
        return result ;*/
        vector<int>result;
        for(int i=0;i<n;i++){
            for(int k=i+1;k<n;k++){
                int sum=nums[i]+nums[k];
                if(sum==target){
                    result.push_back(i);
                    result.push_back(k);
                    return result;
                }
            }
        }
        return result;

    }    
};