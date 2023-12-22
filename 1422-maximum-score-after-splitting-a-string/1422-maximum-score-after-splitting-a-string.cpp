class Solution {
public:
    int maxScore(string s) {
        int best = INT_MIN, zeros = 0, ones = 0;
        
        for (int i = 0; i < s.size() - 1; ++i){
            if (s[i] == '1')
                ++ones;
            else
                ++zeros;
            best = max(best, zeros - ones);
        }
        
        if (s.back() == '1')
            ++ones;
        
        return best + ones;
    }
};