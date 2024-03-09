class Solution:
    def commonPrefix(self, left: str, right: str) -> str:
        mn = min(len(left), len(right))
        for i in range(mn):
            if left[i] != right[i]:
                return left[:i]
        
        return left[:mn]
    
    def _longestCommonPrefix(self, s: List[str], l: int, r: int) -> str:
        if l == r:
            return s[l]
        else:
            mid = (l + r) >> 1
            lcp_left = self._longestCommonPrefix(s, l, mid)
            lcp_right = self._longestCommonPrefix(s, mid + 1, r)
            return self.commonPrefix(lcp_left, lcp_right)
    
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs or len(strs) == 0:
            return ""
        return self._longestCommonPrefix(strs, 0, len(strs) - 1)