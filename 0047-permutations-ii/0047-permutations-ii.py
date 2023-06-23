class Solution:
    def backtrack(self, curr: List[int], cnt: Dict[int, int], ans: List[List[int]]) -> None:
        if len(curr) == self.n:
            ans.append(curr[:])
            return
        
        for num in cnt:
            if cnt[num] > 0:
                curr.append(num)
                cnt[num] -= 1
                self.backtrack(curr, cnt, ans)
                curr.pop()
                cnt[num] += 1
    
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        ans, counter, self.n = [], dict(), len(nums)
        for num in nums:
            counter[num] = counter.get(num, 0) + 1
        
        self.backtrack([], counter, ans)
        
        return ans