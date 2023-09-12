class Solution {
public:
    int minDeletions(string s) {
        
        // store the frequency of each character
        vector<int> frequencies(26);
        for (char& c : s) ++frequencies[c - 'a'];
        sort(frequencies.begin(), frequencies.end(), greater<int>());
        // maximum frequency the current character can have
        int ans = 0, maxFreqAllowed = s.size();
        
        // Iterate over the frequencies in descending order
        for (int i = 0; i < 26; ++i){
            // Delete characters to make the frequency equal the maximum frequency allowed
            if (frequencies[i] > maxFreqAllowed){
                ans += frequencies[i] - maxFreqAllowed;
                frequencies[i] = maxFreqAllowed;
            }
            // Update the maximum allowed frequency
            maxFreqAllowed = max(0, frequencies[i] - 1);
        }
        
        return ans;
    }
};