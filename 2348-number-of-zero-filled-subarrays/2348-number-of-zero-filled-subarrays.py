class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        total, arr_0 = 0, []
        
        for i in range(len(nums)):
            if nums[i] == 0:
                arr_0.append(nums[i])
                if i == len(nums) - 1:
                    total += len(arr_0) * (len(arr_0) + 1) // 2
                    arr_0 = []
                
            else:
                total += len(arr_0) * (len(arr_0) + 1) // 2
                arr_0 = []
        
        return total