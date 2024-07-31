class Solution {
private:
    int n, shelfWidth;
    int dp(int i, int remain, int maxHeightPrev, const vector<vector<int>>& books, vector<vector<int>>& memo){
        // Base case
        if (i == n) return maxHeightPrev;
        
        if (memo[i][remain] != -1)
            return memo[i][remain];
        
        int minHeight = INT_MAX;
        
        if (remain >= books[i][0]){
            minHeight = min(dp(i + 1, remain - books[i][0], max(maxHeightPrev, books[i][1]), books, memo), maxHeightPrev + dp(i + 1, \
                                                                                                              shelfWidth - books[i][0],\
                                                                                                              books[i][1], books, memo));
        }
        else
            minHeight = maxHeightPrev + dp(i + 1, shelfWidth - books[i][0], books[i][1], books, memo);
        
        return memo[i][remain] = minHeight;
    }
    
    
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        this -> n = books.size(), this -> shelfWidth = shelfWidth;
        vector<vector<int>> memo(n + 1, vector<int> (shelfWidth + 1, -1));
        
        return dp(0, shelfWidth, 0, books, memo);
    }
};