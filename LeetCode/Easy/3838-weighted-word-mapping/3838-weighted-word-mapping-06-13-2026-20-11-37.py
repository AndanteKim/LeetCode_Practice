class Solution:
    def mapWordWeights(self, words: List[str], weights: List[int]) -> str:
        ans = []
        for word in words:
            s = 0
            for c in word:
                s += weights[ord(c) - 97]
            ans.append(chr(122 - s % 26))

        return "".join(ans)