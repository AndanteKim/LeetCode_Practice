class Solution {
public:
    long long numberOfSubstrings(string s) {
        long long ans = 0;
        vector<int> chars(26);
        
        for (char& c:s)
            ++chars[c - 'a'];
        
        for (int i = 0; i < 26; ++i)
            if (chars[i] > 0) ans += (((long long)chars[i] * (chars[i] + 1)) >> 1);
        
        return ans;
    }
};