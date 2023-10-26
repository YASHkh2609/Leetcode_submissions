class Solution {
public:
    void getCombination(string digits, vector<string>&ans,string keys[], string str, int i){
        if(i==digits.length()){
            ans.push_back(str);
            return;
        }
        int digit=digits[i]-'0';
        for(int k=0;keys[digit][k]!='\0';k++){
            
            str+=keys[digit][k];
            getCombination(digits, ans, keys, str, i+1);
            str.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        string keys[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        string str;
        if(digits.length()==0)return ans;
        getCombination(digits,ans,keys, str,0);
        return ans;
    }
};