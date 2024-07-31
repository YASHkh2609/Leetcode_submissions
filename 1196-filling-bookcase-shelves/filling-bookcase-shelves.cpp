class Solution {
private:
    int helper(int book, int remainingWidth, int curHeight, int shelfWidth, vector<vector<int>>& books, vector<vector<int>>&dp){
        //basecase
        int maxHeight = max(curHeight, books[book][1]);
        if(book == books.size()-1){
            if(books[book][0]<=remainingWidth){
                return maxHeight;
            }
            return curHeight+books[book][1];
        }
        if(dp[book][remainingWidth]!=-1)return dp[book][remainingWidth];
        int same_shelf =INT_MAX;
        if(books[book][0]<=remainingWidth){
            same_shelf= helper(book+1,remainingWidth - books[book][0], maxHeight, shelfWidth, books, dp);
        }
        int new_shelf = curHeight + helper(book+1, shelfWidth - books[book][0], books[book][1], shelfWidth, books, dp);

        return dp[book][remainingWidth] = min(same_shelf, new_shelf);
    }
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
        vector<vector<int>>dp(n, vector<int>(shelfWidth+1, -1));
        return helper(0, shelfWidth, 0, shelfWidth, books, dp);
    }
};