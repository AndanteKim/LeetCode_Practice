class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ans, self.n = [], len(nums)
        nums.sort()
        for i in range(self.n):
            if nums[i] > 0:
                break
            
            if i == 0 or nums[i - 1] != nums[i]:
                self.twoSum(nums, i, ans)
       
        return ans
    
    def twoSum(self, nums: List[int], i: int, ans: List[List[int]]) -> None:
        seen = set()
        j = i + 1
        
        while j < self.n:
            complement = -nums[i] - nums[j]
            if complement in seen:
                ans.append([nums[i], nums[j], complement])
                while j + 1 < self.n and nums[j] == nums[j + 1]:
                    j += 1
            seen.add(nums[j])
            j += 1
            