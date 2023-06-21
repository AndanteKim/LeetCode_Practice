class Solution:
    def backtrack(self, digit: int, start: int, curr: int, seen: Set[int], k: int, ans: List[int]) -> None:
        if digit == 0:
            if curr not in seen:
                seen.add(curr)
                ans.append(curr)
            return
        if 0 <= start - k < 10:
            self.backtrack(digit - 1, start - k, curr + (start * (10 ** (digit - 1))), seen, k, ans)
        
        if 0 <= start + k < 10:
            self.backtrack(digit - 1, start + k, curr + (start * (10 ** (digit - 1))), seen, k, ans)
        
    
    def numsSameConsecDiff(self, n: int, k: int) -> List[int]:
        ans, seen = [], set()
        for i in range(1, 10):
            self.backtrack(n, i, 0, seen, k, ans)
        
        return ans