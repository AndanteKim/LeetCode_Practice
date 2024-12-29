class Solution:
    mod = 10 ** 9 + 7
    def numWays(self, words: List[str], target: str) -> int:
        
        dp = [[-1] * len(target) for _ in range(len(words[0]))]
        char_freq = [[0] * 26 for _ in range(len(words[0]))]

        # Store the frequency of every character at every index.
        for word in words:
            for j in range(len(word)):
                char_freq[j][ord(word[j]) - 97] += 1
            
        return self.__get_words(words, target, 0, 0, dp, char_freq)
    
    def __get_words(self, words: List[str], target: str, words_idx: int, \
    target_idx: int, dp: List[List[int]], char_freq: List[List[int]]) -> int:
        if target_idx == len(target):
            return 1

        if words_idx == len(words[0]) or len(words[0]) - words_idx < len(target) - target_idx: 
            return 0

        if dp[words_idx][target_idx] != -1:
            return dp[words_idx][target_idx]
        
        count_ways = 0
        curr_pos = ord(target[target_idx]) - 97

        # Don't match any character of target with any word.
        count_ways += self.__get_words(words, target, words_idx + 1, target_idx, dp, char_freq)

        # Multiply the nubmer of choirces with the function and add it to count.
        count_ways += char_freq[words_idx][curr_pos] * self.__get_words(
            words, target, words_idx + 1, target_idx + 1, dp, char_freq
        )
        
        dp[words_idx][target_idx] = count_ways % self.mod
        return dp[words_idx][target_idx]