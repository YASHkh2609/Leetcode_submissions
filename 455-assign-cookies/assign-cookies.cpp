class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int cnt=0;
        int si=0;
        int gi=0;
        while(si<s.size()){
            if(s[si]>=g[gi]){
                cnt++;
                gi++;
            }
            if(gi==g.size())return cnt;
            si++;
        }
        return cnt;
    }
};