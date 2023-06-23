class Solution:
    def backtrack(self, remain: int, start: int, curr: List[int], candidates: List[int], ans: List[List[int]]) -> None:
        if remain == 0:
            ans.append(curr[:])
            return
        
        seen = set()
        for i in range(start, len(candidates)):
            if candidates[i] <= remain and candidates[i] not in seen:
                curr.append(candidates[i])
                self.backtrack(remain - candidates[i], i + 1, curr, candidates, ans)
                curr.pop()
                seen.add(candidates[i])
    
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        candidates.sort()
        self.backtrack(target, 0, [], candidates, ans)
        
        return ans