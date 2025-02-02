class Solution:
    def check(self, nums: List[int]) -> bool:
        sorted_nums, n = nums[:], len(nums)
        sorted_nums.sort()
        
        for i in range(n):
            matching = True
            for j in range(n):
                if sorted_nums[(i + j) % n] != nums[j]:
                    matching = False
                    break

            if matching:
                return True 

        return False