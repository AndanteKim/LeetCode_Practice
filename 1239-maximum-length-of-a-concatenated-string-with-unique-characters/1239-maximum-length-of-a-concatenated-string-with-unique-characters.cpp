class Solution {
private:
    int addWord(string& word, unordered_set<int>& results){
        // Initialize an int used as a character set
        int charBitset = 0, ans = 0;
        
        for (char& c:word){
            // Define character mask for current char
            int mask = 1 << (c - 'a');
            
            // Bitwise AND check using chaaracter mask
            // to see if char already found and if so, exit
            if ((charBitset & mask) > 0)
                return 0;
            
            // Mark char as seen in charBitset
            charBitset += mask;
        }
        
        // If the initial bitset is already a known results,
        // then any possible new results will have already been found
        if (results.find(charBitset + (word.size() << 26)) != results.end())
            return 0;
        
        // Iterate through previous results only
        // and store new results in newResults
        unordered_set<int> newResults;
        for (int res:results){
            // If the two bitsets overlap, skip to the next result
            if (res & charBitset)
                continue;
            
            // Build the new entry with bit manipulation
            int newResLen = (res >> 26) + word.size();
            int newCharBitset = (charBitset + res) & ((1 << 26) - 1);
            
            // Merge the two into one, add it to results,
            // and keep track of the longest so far
            newResults.insert((newResLen << 26) + newCharBitset);
            ans = max(ans, newResLen);
        }
        
        // Merge newResults into results
        results.insert(newResults.begin(), newResults.end());
        return ans;
    }
    
public:
    int maxLength(vector<string>& arr) {
        // Results initialized as a set to prevent duplicates
        unordered_set<int> results({0});
        int ans = 0;
        
        // check each string in arr and find the best length
        for (string& word:arr){
            ans = max(ans, addWord(word, results));
        }
        
        return ans;
    }
};