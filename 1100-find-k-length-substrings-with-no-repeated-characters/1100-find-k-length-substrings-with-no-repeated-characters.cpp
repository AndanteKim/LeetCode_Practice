class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        // Base case
        if (s.size() < k) return 0;

        int ans = 0, n = s.size(), left = 0;
        // Count the frequency of characters to do not repeat
        unordered_map<char, int> freqs;

        // Loop through starting the right pointer
        for (int right = 0; right < n; ++right){
            ++freqs[s[right]];

            // If we found there's repeated characters, move the left pointer until its character of frequency goes 1.
            while (left < right && freqs[s[right]] > 1)
                --freqs[s[left++]];

            // If K-length substrings satisfied, then count the answer.
            if (right - left + 1 >= k) ++ans;
        }

        return ans;
    }
};