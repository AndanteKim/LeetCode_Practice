class Solution {
private:
    int findSequences(unordered_map<char, int>& charCount){
        int total = 0;

        // Try using each available character
        for (auto& [ch, freq] : charCount){
            if (charCount[ch] == 0) continue;

            // Add current character and recurse
            ++total;
            --charCount[ch];
            total += findSequences(charCount);
            ++charCount[ch];
        }

        return total;
    }

public:
    int numTilePossibilities(string tiles) {
        // Track frequency of each characters
        unordered_map<char, int> charCount;
        for (const char& c : tiles) ++charCount[c];

        // Find all possible sequences using character frequencies
        return findSequences(charCount);
    }
};