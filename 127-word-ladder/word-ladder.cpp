class Solution {
public:
    // int count_diffchar(string s1, string s2){
    //     int cnt=0;
    //     for(int i=0;i<s1.length();i++){
    //         if(s1[i]!=s2[i])cnt++;
    //     }
    //     return cnt;
    // }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // int N= wordList.size()+1;
        // unordered_map<string, int>mpp;
        // for(int i=0;i<N;i++){
        //     if(i==0)mpp[beginWord]=0;
        //     else{
        //         mpp[wordList[i-1]]=i;
        //     }
        // }
        // vector<vector<int>>adj(N);
        // for(int i=0;i<N-1;i++){
        //     if(count_diffchar(wordList[i], beginWord)==1){
        //         adj[mpp[wordList[i]]].push_back(mpp[beginWord]);
        //         adj[mpp[beginWord]].push_back(mpp[wordList[i]]);
        //     }
        //     for(int j=0;j<N-1;j++){
        //         if(count_diffchar(wordList[i], wordList[j])==1){
        //             adj[mpp[wordList[i]]].push_back(mpp[wordList[j]]);
        //             adj[mpp[wordList[j]]].push_back(mpp[wordList[i]]);
        //         }
        //     }
        // }
        // queue<pair<int,int>>q;
        // q.push({mpp[beginWord],0});
        
        // vector<int>dist(N, INT_MAX);
        // dist[mpp[beginWord]]=0;
        // while(!q.empty()){
        //     int node=q.front().first;
        //     int d=q.front().second;

        //     q.pop();

        //     for(auto it: adj[node]){
        //         if((d+1)<dist[it]){
        //             dist[it]=d+1;
        //             q.push({it,(d+1)});
        //         }
        //     }
        // }
        // int ans=0;
        // if(mpp.find(endWord)!=mpp.end() && dist[mpp[endWord]]!=INT_MAX){
        //     ans=dist[mpp[endWord]]+1;
        // }
        // //for(auto it:dist)cout<<it<<" ";
        // return ans;
        set<string>st(wordList.begin(), wordList.end());
        queue<pair<string, int>>q;
        q.push({beginWord, 1});
        st.erase(beginWord);
        while(!q.empty()){
            string word=q.front().first;
            int steps=q.front().second;
            if(word==endWord)return steps;

            q.pop();

            for(int i=0;i<word.length();i++){
                char og= word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        q.push({word, steps+1});
                        st.erase(word);
                    }
                }
                word[i]=og;
            }
        }
        return 0;
    }
};