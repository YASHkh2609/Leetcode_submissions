class Solution {
private:
    static bool compare(pair<int, int>&a, pair<int, int>&b){
        if(a.first==b.first)
            return a.second>b.second;
        return a.first<b.first;
    }
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }

        vector<pair<int,int>>freq_val;

        for(auto it:mpp){
            freq_val.push_back({it.second, it.first});
        }

        sort(freq_val.begin(), freq_val.end(), compare);

        vector<int>ans;

        for(auto it:freq_val){
            int freq=it.first;
            int val=it.second;

            while(freq--){
                ans.push_back(val);
            }
        }
        return ans;
    }
};