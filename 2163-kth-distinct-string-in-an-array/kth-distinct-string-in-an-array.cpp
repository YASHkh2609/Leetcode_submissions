class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int cnt_distinct=0;
        for(int i=0;i<arr.size();i++){
            int cnt=1;
            for(int j=0;j<arr.size();j++){
                if(i!=j && arr[i]==arr[j])cnt++;
            }
            if(cnt==1)cnt_distinct++;
            if(cnt_distinct==k)return arr[i];
        }
        return "";
    }
};