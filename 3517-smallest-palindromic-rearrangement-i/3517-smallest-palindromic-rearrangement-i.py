class Solution:
    def smallestPalindrome(self, s: str) -> str:
        partition = len(s) >> 1
        base = sorted(s[:partition])
        mid = [s[partition]] if len(s) % 2 else []
        reverse = base[::-1]
        
        return "".join(base + mid + reverse)