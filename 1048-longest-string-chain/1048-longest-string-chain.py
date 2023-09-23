class Solution:
    def dfs(self, words: Set[str], memo: Dict[str, int], current_word: str) -> int:
        # If the word is encountered previously we just return its value present in the map(memoization)
        if current_word in memo:
            return memo[current_word]
        
        # This stores the maximum length of word sequence possible with the 'currentWord' as the
        # creating all possible strings taking out one character at a time from the current_word
        max_length = 1
        
        for i in range(len(current_word)):
            new_word = current_word[:i] + current_word[i + 1:]
            # If the new word formed is present in the list, we do a dfs search with this new word
            if new_word in words:
                curr_length = 1 + self.dfs(words, memo, new_word)
                max_length = max(max_length, curr_length)
        memo[current_word] = max_length
        return max_length
    
    def longestStrChain(self, words: List[str]) -> int:
        memo, words_present = dict(), set()
        
        for word in words:
            words_present.add(word)
        
        ans = 0
        for word in words:
            ans = max(ans, self.dfs(words_present, memo, word))
        
        return ans
        