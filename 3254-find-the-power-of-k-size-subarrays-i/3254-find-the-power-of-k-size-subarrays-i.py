class Solution:
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)

        ans = [-1] * (n - k + 1)
        
        for i in range(n - k + 1):
            right, is_power = i + k, True
            while i < right - 1:
                if nums[i] + 1 != nums[i + 1]:
                    is_power = False
                    break
                i += 1
            if is_power:
                ans[right - k] = nums[i]
            
        return ans