class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int, int>mpp; 
        for(int i=0;i<nums2.size();i++){
            nums2[i] = nums2[i] * k;
            mpp[nums2[i]]++;
        }
        long long pair_count=0;
        for(int i=0;i<nums1.size();i++){
            for(int j=1;j*j<=nums1[i];j++){
                if(nums1[i]%j==0){
                    pair_count+=mpp[j];
                    if(j*j!=nums1[i]){
                        pair_count+=mpp[(nums1[i]/j)];
                    }
                }
            }
        }
        return pair_count;
    }
};