class Solution {
public:
    int minimumLength(string s) {
        // Step 1: Count the frequency of each character in the string
        unordered_map<char, int> charFrequencyMap;
        for (const char& c : s)
            ++charFrequencyMap[c];
        
        // Step 2: Calculate the number of characters to delete
        int deleteCount = 0;
        for (const auto& [_, freq] : charFrequencyMap){
            if (freq % 2)
                // If frequency is odd, delete all except one
                deleteCount += freq - 1;
            else
                // If frequency is even, delete all except two
                deleteCount += freq - 2;
        }

        // Step 3: Return the minimum length after deletions
        return s.size() - deleteCount;
    }
};