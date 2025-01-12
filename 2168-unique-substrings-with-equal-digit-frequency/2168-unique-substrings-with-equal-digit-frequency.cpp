class Solution {
public:
    int equalDigitFrequency(string s) {
        int n = s.size();
        
        // Set to store unique substrings with equal digit frequency
        unordered_set<string> seen;

        // Iterate over each possible starting position of a substring
        for (int start = 0; start < n; ++start){
            vector<int> digitFrequency(10, 0);

            // Extend the substring from 'start' to different end positions
            for (int end = start; end < n; ++end){
                ++digitFrequency[s[end] - 48];
                // Variable to store the frequency all digits must match
                int commonFrequency = 0;
                bool isValid = true;

                for (int i = 0; i < 10; ++i){
                    // Skip digits that are not in the substring
                    if (digitFrequency[i] == 0)
                        continue;

                    if (commonFrequency == 0)
                        // First digit found, set commonFrequency
                        commonFrequency = digitFrequency[i];
                    
                    if (digitFrequency[i] != commonFrequency){
                        // Mismatch in frequency mark as invalid
                        isValid = false;
                        break;
                    }
                }
                
                // If the substring is valid, add it to the set
                if (isValid)
                    seen.insert(s.substr(start, end - start + 1));
            }
        }

        // Return the number of unique valid substrings
        return seen.size();
    }
};