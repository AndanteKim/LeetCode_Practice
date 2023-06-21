class Solution:
    def getCost(self, base: int, nums: List[int], cost: List[int]) -> int:
        return sum(abs(base - num) * c for num, c in zip(nums, cost))
    
    def minCost(self, nums: List[int], cost: List[int]) -> int:
        left, right = min(nums), max(nums)
        ans = self.getCost(nums[0], nums, cost)
        
        while left < right:
            mid = (left + right) >> 1
            cost_1 = self.getCost(mid, nums, cost)
            cost_2 = self.getCost(mid + 1, nums, cost)
            ans = min(cost_1, cost_2)
            
            if cost_1 > cost_2:
                left = mid + 1
            else:
                right = mid
        
        return ans