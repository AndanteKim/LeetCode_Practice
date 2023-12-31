class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        ans, n, idx_list = -1, len(s), defaultdict(list)
        
        for i in range(n):
            idx_list[s[i]].append(i)
        
        for char, indices in idx_list.items():
            for i in range(1, len(indices)):
                ans = max(ans, indices[-1] - indices[0] - 1)
        
        return ans