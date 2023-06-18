class Solution:
    def backtrack(self, start: int, n: int, k: int, curr: List[int], ans: List[List[int]]) -> None:
        if len(curr) == k:
            ans.append(curr[:])
            return
        
        for i in range(start, n + 1):
            curr.append(i)
            self.backtrack(i + 1, n, k, curr, ans)
            curr.pop()
        
    
    def combine(self, n: int, k: int) -> List[List[int]]:
        ans = []
        self.backtrack(1, n, k, [], ans)
        
        return ans