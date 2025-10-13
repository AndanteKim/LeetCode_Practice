class Solution:
    def removeAnagrams(self, words: List[str]) -> List[str]:
        prev, ans = "", []

        for word in words:
            chars, flat = Counter(word), ""
            for c, freq in sorted(chars.items()):
                flat += c + str(freq)

            if flat == prev:
                continue
            
            ans.append(word)
            prev = flat
        
        return ans