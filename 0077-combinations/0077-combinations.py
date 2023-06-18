class Solution:
    def backtrack(self, start: int, n: int, k: int, curr: List[int], ans: List[List[int]]) -> None:
        if start > n:
            return
        
        if len(curr) == k:
            ans.append(curr[:])
            return
        
        for i in range(start, n):
            if len(curr) < k:
                curr.append(i + 1)
                self.backtrack(i + 1, n, k, curr, ans)
                curr.pop()
        
    
    def combine(self, n: int, k: int) -> List[List[int]]:
        ans = []
        self.backtrack(0, n, k, [], ans)
        
        return ans