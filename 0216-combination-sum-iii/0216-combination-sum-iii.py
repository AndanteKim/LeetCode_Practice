class Solution:
    def backtrack(self, curr: List[int], start: int, length: int, remain: int, ans: List[List[int]]) -> None:
        if length == 0:
            if remain == 0:
                ans.append(curr[:])
            return
        
        for i in range(start, 10):
            curr.append(i)
            self.backtrack(curr, i + 1, length - 1, remain - i, ans)
            curr.pop()
    
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        ans = []
        self.backtrack([], 1, k, n, ans)
        
        return ans