class Solution:
    def beautifulSubsets(self, nums: List[int], k: int) -> int:
        def backtrack(i: int, curr: List[int]) -> None:
            if i == n:
                if len(curr) > 0:
                    ans.append(curr[:])
                return
            
            if not curr or (nums[i] - k not in curr and nums[i] + k not in curr):
                curr.append(nums[i])
                backtrack(i + 1, curr)
                curr.pop()
                backtrack(i + 1, curr)
            else:
                backtrack(i + 1, curr)
        
        ans, n = [], len(nums)
        backtrack(0, [])
        return len(ans)