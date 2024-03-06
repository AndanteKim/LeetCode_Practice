class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> values{
            {'I', 1}, {'V', 5}, {'X', 10}, \
            {'L', 50}, {'C', 100}, {'D', 500}, \
            {'M', 1000}
        };
        int i = 0, n = s.size(), ans = 0;
        
        while (i < n){
            // If this is subtractive case
            if (i + 1 < n && values[s[i]] < values[s[i + 1]]){
                ans += values[s[i + 1]] - values[s[i]];
                i += 2;
            }
            else{
                // If this is not subtractive case
                ans += values[s[i]];
                ++i;
            }
        }
        
        return ans;
    }
};