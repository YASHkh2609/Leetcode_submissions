class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // int cnt=0;
        // for(int i=0;i<nums.size();i++){
        //     int sum=0;
        //     for(int j=i;j<nums.size();j++){
        //         sum+=nums[j];
        //         if(sum==goal)cnt++;
        //     }
        // }
        // return cnt;
        unordered_map<int, int> count;
        count[0] = 1;
        int curr_sum = 0;
        int total_subarrays = 0;

        for (int num : nums) {
            curr_sum += num;
            if (count.find(curr_sum - goal) != count.end()) {
                total_subarrays += count[curr_sum - goal];
            }
            count[curr_sum]++;
        }

        return total_subarrays;
    }
};