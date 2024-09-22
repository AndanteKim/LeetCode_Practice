class Solution {
public:
    string longestWord(vector<string>& words) {
        string longestValidWord = "";
        
        // Sort the words by lexicographically order
        sort(words.begin(), words.end());
        // Set to store valid words
        unordered_set<string> validWords;
        
        // Iterate through each word
        for (const string& word : words){
            // Check if the word is of length 1 or if its prefix exists in the set
            if (word.size() == 1 || validWords.count(word.substr(0, word.size() - 1))){
                // Add the current word to the set of valid words
                validWords.insert(word);
                
                // Update the longest valid word if necessary
                if (word.size() > longestValidWord.size())
                    longestValidWord = word;
            }
        }
        
        // Return the longest valid word found
        return longestValidWord;
    }
};