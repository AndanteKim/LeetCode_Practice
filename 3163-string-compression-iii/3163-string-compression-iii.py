class Solution:
    def compressedString(self, word: str) -> str:
        frequency, word_order, prev = defaultdict(int), [], ''
        ans, n = "", len(word)
        for i in range(n):
            if prev != '' and prev != word[i]:
                while frequency[prev] > 0:
                    ans += str(min(frequency[prev], 9)) + prev
                    frequency[prev] -= min(frequency[prev], 9)
            frequency[word[i]] += 1
            prev = word[i]
            
            if i == n - 1:
                while frequency[word[i]] > 0:
                    ans += str(min(frequency[word[i]], 9)) + word[i]
                    frequency[word[i]] -= min(frequency[word[i]], 9)
        
        return ans