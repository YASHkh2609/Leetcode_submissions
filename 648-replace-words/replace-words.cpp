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
                if(st.find(temp[i].substr(0,j))!=st.end()){
                    auto it=st.find(temp[i].substr(0,j));
                    //cout<<*it<<" ";
                    temp[i]=*it;
                    break;
                }
            }
        }
        string ans="";
        for(int i=0;i<temp.size();i++){
            ans+=temp[i];
            if(i!=temp.size()-1)
                ans+=" ";
        }
        return ans;
    }
};