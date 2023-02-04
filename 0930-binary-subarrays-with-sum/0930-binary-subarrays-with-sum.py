class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        
        cnts = defaultdict(int)
        cnts[0] = 1
        ans = curr = 0
        
        for num in nums:
            curr += num
            ans += cnts[curr - goal]
            cnts[curr] += 1
        return ans