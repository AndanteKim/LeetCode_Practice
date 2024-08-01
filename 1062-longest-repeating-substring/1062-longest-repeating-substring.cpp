class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int n = s.size();
        vector<string> suffixes;
        
        // Create suffix array by storing all suffixes of the string
        for (int i = 0; i < n; ++i)
            suffixes.push_back(s.substr(i));
        
        // Sort the suffix array
        sort(suffixes.begin(), suffixes.end());
        int maxLen = 0;
        
        // Compare adjacent suffixes to find the longest common prefix
        for (int i = 1; i < n; ++i){
            int j = 0;
            
            // Compare characters one by one until they differ or end of one
            // suffix is reached
            while (j < min(suffixes[i].size(), suffixes[i - 1].size()) && suffixes[i][j] == suffixes[i - 1][j])
                ++j;
            
            // Update max length with the length of the common prefix
            maxLen = max(maxLen, j);
        }
        
        return maxLen;
    }
};