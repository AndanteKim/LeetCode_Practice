class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (trust.size() < n - 1) return -1;
        int scores[n+1];
        fill_n(scores, n+1, 0);
        
        for (const auto &t : trust){
            --scores[t[0]];
            ++scores[t[1]];
        }
        
        for (int i = 1; i <= n; ++i){
            if (scores[i] == n - 1) return i;
        }
        return -1;
    }
};