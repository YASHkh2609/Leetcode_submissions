class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        set<string>st;
        for(int i=0;i<dictionary.size();i++){
            st.insert(dictionary[i]);
        }
        vector<string>temp;
        int i=0, j=0;
        while(j<sentence.length()){ 
            if(sentence[j]==' '){
                temp.push_back(sentence.substr(i,j-i));
                i=j+1;
            }
            j++;
        }
        temp.push_back(sentence.substr(i,j-i));

        for(int i=0;i<temp.size();i++){
            for(int j=1;j<=temp[i].length();j++){
                string prefix=temp[i].substr(0,j);
                if(st.find(prefix)!=st.end()){
                    temp[i]=prefix;
                    break;
                }
            }

        }
        string ans="";
        for(int i=0;i<temp.size();i++){
            ans+=temp[i]+" ";
        }
        ans.erase(ans.size()-1);
        return ans;
    }
};