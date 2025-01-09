class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        p, ans = len(pref), 0

        for word in words:
            if len(word) < p:
                continue
            j = 0
            for i in range(p):
                if word[i] == pref[i]:
                    j += 1
            if j == p:
                ans += 1
        
        return ans