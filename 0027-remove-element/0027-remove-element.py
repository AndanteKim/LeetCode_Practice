class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        i, j, cnt = 0, len(nums) - 1, 0
        while i <= j:
            if nums[j] == val:
                j -= 1
                cnt += 1
                continue
            elif nums[i] == val:
                nums[i], nums[j] = nums[j], nums[i]
                cnt += 1
                j -= 1
            i += 1
        
        return len(nums) - cnt