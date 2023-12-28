class Solution {
private:
    unordered_map<int, int> memo;
    set<int> add{1, 9, 99};
    int dp(string& s, int i, char lastChar, int lastCharCount, int k){
        if (k < 0)
            return INT_MAX / 2;
        
        if (i == s.size())
            return 0;
        
        int key = i * 101 * 27 * 101 + (lastChar - 'a') * 101 * 101 + lastCharCount * 101 + k;
        if (memo.find(key) != memo.end())
            return memo[key];
        
        int keepChar;
        int deleteChar = dp(s, i + 1, lastChar, lastCharCount, k - 1);
        if (s[i] == lastChar)
            keepChar = dp(s, i + 1, lastChar, lastCharCount + 1, k) + add.count(lastCharCount);
        else
            keepChar = dp(s, i + 1, s[i], 1, k) + 1;
        int ans = min(keepChar, deleteChar);
        return memo[key] = ans;
    }
    
public:
    int getLengthOfOptimalCompression(string s, int k) {
        return dp(s, 0, (char)('a' + 26), 0, k);
    }
};