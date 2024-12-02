class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        // Initialize a string stream to read words from the sentence
        istringstream sentenceStream(sentence);
        string currentWord;
        
        // Start counting word positions from 1
        int wordPosition = 1;
        
        // Loop through each word in the sentence
        while (sentenceStream >> currentWord){
            // Check if the current word is long enough to contain the
            // searchWord as a prefix and if the prefix matches the searchWord
            if (currentWord.size() >= searchWord.size() && \
               currentWord.compare(0, searchWord.size(), searchWord) == 0){
                // If a match is found, return the current word position
                return wordPosition;
            }
            
            // Move to the next word position
            ++wordPosition;
        }
        
        // If no match is found, return -1
        return -1;
    }
};