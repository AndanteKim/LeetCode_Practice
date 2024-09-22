class Solution:
    def longestWord(self, words: List[str]) -> str:
        # Sort the words lexicographically
        words.sort()
        
        # Set to store valid words
        valid_words = set()
        longest_valid_word = ""
        
        # Iterate through each word
        for word in words:
            # Check if the word of length 1 or if its prefix exists in the set
            if len(word) == 1 or word[:-1] in valid_words:
                # Add the current word to the set of valid words
                valid_words.add(word)
            
                # Update the longest valid word if necessary
                if len(word) > len(longest_valid_word):
                    longest_valid_word = word
                
        # Return the longest valid word found
        return longest_valid_word