class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size(), partition = n >> 1;
        vector<int> bucket(26);

        for (int i = 0; i < partition; ++i) ++bucket[s[i] - 'a'];

        int left = 0, right = n - 1;

        for (int i = 0; i < 26; ++i) {
            while (bucket[i]-- > 0) {
                char c = i + 'a';
                s[left++] = c;
                s[right--] = c;
            }
            
        }

        return s;
    }
};