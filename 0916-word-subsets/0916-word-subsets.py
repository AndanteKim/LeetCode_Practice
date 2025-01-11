class Solution:
    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
        def count(word: str) -> List[int]:
            ans = [0] * 26
            for c in word:
                ans[ord(c) - 97] += 1
            return ans

        w2_max = [0] * 26
        for w2 in words2:
            for i, c in enumerate(count(w2)):
                w2_max[i] = max(w2_max[i], c)
        
        ans = []

        for w1 in words1:
            available = True
            for x, y in zip(count(w1), w2_max):
                if x < y:
                    available = False
                    break

            if available:
                ans.append(w1)

        return ans