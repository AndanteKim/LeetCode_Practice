class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        cnt = 0
        ump = defaultdict(int)
        for i in range(len(nums)):
            if ump[nums[i]] > 0:
                cnt += ump[nums[i]]
            ump[nums[i]] += 1
            
        return cnt