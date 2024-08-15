class Solution {
public:
    int minMoves(vector<vector<int>>& rooks) {
        int ans = 0, n = rooks.size();
        
        sort(rooks.begin(), rooks.end(), [](vector<int>& a, vector<int>& b){return a[0] < b[0];});
        // Moves required to place rooks in each row 
        for (int i = 0; i < n; ++i)
            ans += abs(rooks[i][0] - i);
            
        sort(rooks.begin(), rooks.end(), [](vector<int>& a, vector<int>& b){return a[1] < b[1];});
        // Moves required to place rooks in each column
        for (int i = 0; i < n; ++i)
            ans += abs(rooks[i][1] - i);
        
        return ans;
    }
};