class Solution:
    def backtrack(self, start: int, k: int, n: int, curr: List[int], total: int, ans: List[List[int]]) -> None:
        if k == 0:
            if total == n:
                ans.append(curr[:])
            return
        
        for i in range(start, 10):
            if total + i <= n:
                curr.append(i)
                self.backtrack(i + 1, k - 1, n, curr, total + i, ans)
                curr.pop()
    
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        ans = []
        self.backtrack(1, k, n, [], 0, ans)
        
        return ans