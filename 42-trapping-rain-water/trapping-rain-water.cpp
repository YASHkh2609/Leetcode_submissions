class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int ans=0,wtrap=0;
        int i=0,j=1;
        while(i<n&&j<n){
            if(height[j]>=height[i]){
                i=j;
                j++;
                ans+=wtrap;
                wtrap=0;
            }
            else{
                wtrap+=height[i]-height[j];
                j++;
            }
        }
        wtrap=0;
        i=n-1;
        j=i-1;
        while(i>=0&&j>=0){
            if(height[j]>height[i]){
                i=j;
                j--;
                ans+=wtrap;
                wtrap=0;
            }
            else{
                wtrap+=height[i]-height[j];
                j--;
            }
        }
        return ans;
    }
};