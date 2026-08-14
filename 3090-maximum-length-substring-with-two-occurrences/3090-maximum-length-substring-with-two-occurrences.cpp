class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size(), ans = 0, left = 0;
        unordered_map<char, int> freq;

        for (int right = 0; right < n; ++right) {
            ++freq[s[right]];
            
            while (left < right && freq[s[right]] > 2) {
                --freq[s[left++]];
            }
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};