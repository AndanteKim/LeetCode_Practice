class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size(), partition = n >> 1;
        sort(s.begin(), s.begin() + partition);
        
        for (int i = 0; i < partition; ++i)
            s[n - 1 - i] = s[i];
        
        return s;
    }
};