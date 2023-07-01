class Solution:
    def backtrack(self, i: int, zero_count: int, curr: List[int], cookies: List[int]) -> int:
        if self.n - i < zero_count:
            return float('inf')
        
        if i == self.n:
            return max(curr)
        
        ans = float('inf')
        for j in range(self.k):
            zero_count -= int(curr[j] == 0)
            curr[j] += cookies[i]
            
            ans = min(ans, self.backtrack(i + 1, zero_count, curr, cookies))
            curr[j] -= cookies[i]
            zero_count += int(curr[j] == 0)
        
        return ans
    
    def distributeCookies(self, cookies: List[int], k: int) -> int:
        self.n, curr, self.k = len(cookies), [0] * k, k
        
        return self.backtrack(0, k, curr, cookies)