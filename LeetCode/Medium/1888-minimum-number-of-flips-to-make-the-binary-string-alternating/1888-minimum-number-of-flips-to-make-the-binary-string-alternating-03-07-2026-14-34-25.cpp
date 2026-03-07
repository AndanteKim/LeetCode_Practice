class Solution {
public:
    int minFlips(string s) {
        int flip0 = 0, n = s.size(), start = 48;
        
        for (const char& c : s) {
            if (c != start)
                ++flip0;

            start ^= 1;
        }

        int ans = min(flip0, n - flip0);

        if (!(n & 1)) return ans;

        start = 48;
        for (const char& c : s){
            if (c != start) {
                --flip0;
                ans = min(ans, flip0);
            }
            else {
                ++flip0;
                ans = min(ans, n - flip0);
            }

            start ^= 1;
        }

        return ans;
    }
};