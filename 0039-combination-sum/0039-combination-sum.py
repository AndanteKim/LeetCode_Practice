class Solution:
    def backtrack(self, prefix: int, curr: List[int], candidates: List[int], target: int, ans: List[List[int]]) -> None:
        if prefix >= target:
            if prefix == target:
                ans.append(curr[:])
            return
        
        for i in range(len(candidates)):
            if not curr or (curr and curr[-1] <= candidates[i]):
                curr.append(candidates[i])
                self.backtrack(prefix + candidates[i], curr, candidates, target, ans)
                curr.pop()
    
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        self.backtrack(0, [], candidates, target, ans)
        return ans