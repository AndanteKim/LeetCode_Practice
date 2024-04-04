class Solution:
    def twoSumII(self, nums: List[int], i: int, ans: List[List[int]]) -> None:
        lo, hi = i + 1, self.n - 1
        
        while lo < hi:
            sum = nums[i] + nums[lo] + nums[hi]
            if sum < 0: lo += 1
            elif sum > 0: hi -= 1
            else:
                ans.append([nums[i], nums[lo], nums[hi]])
                lo += 1
                hi -= 1
                
                while lo < hi and nums[lo - 1] == nums[lo]:
                    lo += 1
                
        
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ans, self.n = [], len(nums)
        nums.sort()
        
        for i in range(self.n):
            if nums[i] > 0:
                break
            
            if i == 0 or nums[i] != nums[i - 1]:
                self.twoSumII(nums, i, ans)
                
        return ans