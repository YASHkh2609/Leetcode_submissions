class Solution {
public:
    void create_sieve(bool sieve[], int n){
        for(int i=2;i<=n;i++){
            sieve[i]=true;
        }

        for(int i=2;i*i<=n;i++){
            if(sieve[i]==true){
                for(int j=i*i;j<=n;j+=i){
                    sieve[j]=false;
                }
            }
        }
    }
    int countPrimes(int n) {
        bool sieve[n+1];
        create_sieve(sieve, n);
        int count=0;
        for(int i=2;i<n;i++){
            if(sieve[i]==true)count++;
        }
        return count;
    }
};