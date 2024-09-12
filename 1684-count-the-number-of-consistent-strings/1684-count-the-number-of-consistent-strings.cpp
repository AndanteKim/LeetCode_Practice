class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // Create a bitmask representing the allowed characters
        int allowedBits = 0, consistentCount = 0;
        
        // Set the corresponding bit for each character in allowed
        for (const char& c : allowed)
            allowedBits |= (1 << (c - 97));
        
        // Iterate through each word in the words list
        for (const string& word : words){
            bool isConsistent = true;
            
            // Check each character in the word
            for (const char& c : word){
                // Calculate the bit position for the curretn character
                bool bit = (allowedBits >> (c - 97)) & 1;
                
                // If the bit is 0, the character isn't allowed.
                if (!bit){
                    isConsistent = false;
                    break;
                }
            }
            
            // If the word is consistent, increment the count
            if (isConsistent)
                ++consistentCount;
        }
        
        return consistentCount;
    }
};