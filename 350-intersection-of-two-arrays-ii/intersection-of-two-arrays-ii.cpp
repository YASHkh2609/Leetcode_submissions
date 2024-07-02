class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>map1(1001,0);
        vector<int>map2(1001,0);

        for(auto it:nums1){
            map1[it]++;
        }
        for(auto it:nums2){
            map2[it]++;
        }
        vector<int>ans;
        for(int i=0;i<1001;i++){
            if(map1[i]>0 &&map2[i]>0){
                ans.insert(ans.end(), min(map1[i], map2[i]),i);
            }
        }
        return ans;
    }
};