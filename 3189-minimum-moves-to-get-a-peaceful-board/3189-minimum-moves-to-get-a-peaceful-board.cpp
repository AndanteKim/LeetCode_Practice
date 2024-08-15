class Solution {
public:
    int minMoves(vector<vector<int>>& rooks) {
        int ans = 0, n = rooks.size(), row = 0;
        
        sort(rooks.begin(), rooks.end(), [](vector<int>& a, vector<int>& b){return a[0] < b[0];});
        for (int i = 0; i < n; ++i){
            ans += abs(rooks[i][0] - row++);
        }
        
        sort(rooks.begin(), rooks.end(), [](vector<int>& a, vector<int>& b){return a[1] < b[1];});
        int col = 0;
        for (int i = 0; i < n; ++i)
            ans += abs(rooks[i][1] - col++);
        
        return ans;
    }
};