class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> count(3);
        
        // Count total occurrences
        for (const auto& c : s)
            ++count[c - 97];
        
        // Check if we've enough characters
        for (int i = 0; i < 3; ++i)
            if (count[i] < k) return -1;

        int n = s.size(), maxWindow = 0, left = 0;
        vector<int> window(3);
        
        // Find the longest window leaving k of each character outside
        for (int right = 0; right < n; ++right){
            ++window[s[right] - 97];
            
            // Shrink window if we take too many characters
            while (left <= right && (count[0] - window[0] < k || count[1] - window[1] < k || count[2] - window[2] < k))
                --window[s[left++] - 97];
                
            maxWindow = max(maxWindow, right - left + 1);
        }
        
        return n - maxWindow;
    }
};