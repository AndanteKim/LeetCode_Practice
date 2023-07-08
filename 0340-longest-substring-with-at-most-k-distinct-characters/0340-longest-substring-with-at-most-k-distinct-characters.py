class Solution:
    def isValid(self, size: int, s: str) -> bool:
        counter = Counter(s[:size])
        if len(counter) <= self.k:
            return True
        
        for i in range(size, self.n):
            counter[s[i]] += 1
            counter[s[i - size]] -= 1
            if counter[s[i - size]] == 0:
                del counter[s[i - size]]
            if len(counter) <= self.k:
                return True
        return False
    
    def lengthOfLongestSubstringKDistinct(self, s: str, k: int) -> int:
        self.n, self.k = len(s), k
        if k >= self.n:
            return self.n
        left, right = k, self.n
        
        while left < right:
            mid = left + ((right - left + 1) >> 1)
            if self.isValid(mid, s):
                left = mid
            else:
                right = mid - 1
        
        return left