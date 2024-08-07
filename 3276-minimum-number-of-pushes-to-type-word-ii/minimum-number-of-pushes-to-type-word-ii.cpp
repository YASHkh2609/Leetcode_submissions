class Solution {
private:
    static bool cmp(pair<char, int>&a, pair<char, int>&b){
        return a.second>b.second;
    }
public:
    int minimumPushes(string word) {
        unordered_map<char, int>freq;
        for(int i=0;i<word.length();i++){
            freq[word[i]]++;
        }
        vector<pair<char,int>>vec;
        for(auto it:freq){
            vec.push_back({it.first, it.second});
        }
        sort(vec.begin(), vec.end(), cmp);

        int cnt=0;
        int presses =0;
        for(auto it:vec){
            int num=it.second;
            if(cnt/8==0){
                presses +=num*1;
            }
            else if(cnt/8==1){
                presses+=2*num;
            }
            else if(cnt/8==2){
                presses+=3*num;
            }
            else{
                presses+=4*num;
            }
            cnt++;
        }
        return presses;
    }
};