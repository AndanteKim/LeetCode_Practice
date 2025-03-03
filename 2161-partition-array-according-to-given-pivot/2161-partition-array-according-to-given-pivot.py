class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        ans = [0] * len(nums)
        less_i, greater_i = 0, len(nums) - 1

        for i, j in zip(range(len(nums)), range(len(nums) - 1, -1, -1)):
            if nums[i] < pivot:
                ans[less_i] = nums[i]
                less_i += 1
            
            if nums[j] > pivot:
                ans[greater_i] = nums[j]
                greater_i -= 1
        
        while less_i <= greater_i:
            ans[less_i] = pivot
            less_i += 1
        
        return ans