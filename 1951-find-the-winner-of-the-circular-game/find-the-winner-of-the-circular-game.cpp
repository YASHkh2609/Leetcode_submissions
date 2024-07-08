class Solution {
public:
    int findTheWinner(int n, int k) {
        int cnt=0, minusOnes=0;
        vector<int>temp(n, 0);
        int ptr=0;
        while(minusOnes<n-1){
            while(cnt<k-1){
                if(temp[ptr]!=-1){
                    cnt++;
                }
                ptr=(ptr+1)%n;
            }
            while(temp[ptr]==-1){
                ptr=(ptr+1)%n;
            }
            temp[ptr]=-1;
            ptr=(ptr+1)%n;
            minusOnes++;
            cnt=0;
        }

        while(temp[ptr]==-1){
            ptr=(ptr+1)%n;
        }

        return ptr+1;
    }
};