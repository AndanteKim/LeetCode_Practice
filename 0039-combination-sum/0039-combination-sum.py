class Solution:
    def backtrack(self, path: List[int], start: int, curr: int, candidates: List[int], target: int, ans: List[List[int]]) -> None:
        if curr == target:
            ans.append(path[:])
            return
        
        for i in range(start, len(candidates)):
            if curr + candidates[i] <= target:
                path.append(candidates[i])
                self.backtrack(path, i, curr + candidates[i], candidates, target, ans)
                path.pop()
    
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        self.backtrack([], 0, 0, candidates, target, ans)
        
        return ans