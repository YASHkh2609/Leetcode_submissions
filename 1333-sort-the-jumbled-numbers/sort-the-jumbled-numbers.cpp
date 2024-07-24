class Solution {
private:
    int mapNumber(int num, vector<int>& mapping){
        int mappedNumber=0;
        int i=0;
        if(num==0)return mapping[0];
        while(num>0){
            int digit = num%10;
            num/=10;
            int mappedDigit = mapping[digit];
            mappedNumber = mappedDigit*pow(10,i) + mappedNumber;
            i++;
        }
        return mappedNumber;
    }
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {

        sort(nums.begin(), nums.end(), [&](int a, int b){
            // cout<< mapNumber(a, mapping)<<" "<<mapNumber(b, mapping)<<endl;
            return mapNumber(a, mapping) < mapNumber(b, mapping);
        });
        return nums;
    }
};