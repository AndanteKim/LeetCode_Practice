class Solution {
public:
    int maxScore(string s) {
        // One pass: score = Z_left - O_left + O_total
        int zeros = 0, ones = 0, best = std::numeric_limits<int>::min();

        for (int i = 0; i < s.size() - 1; ++i){
            if (s[i] == '1')
                ++ones;
            else
                ++zeros;
            
            best = max(best, zeros - ones);
        }

        if (s.back() == '1') ++ones;

        return best + ones;
    }
};